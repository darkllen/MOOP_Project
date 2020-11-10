//
// Created by Lemonderon on 20.10.2020.
//

#include "AccountActions.h"
#include "mysqlx/xdevapi.h"
#include "../models/accounts/Account.h"
#include "../models/transactions/Transaction.h"
#include "../models/transactions/OneTimeTransfer.h"
#include "../models/transactions/CashTransaction.h"
#include "../models/transactions/RegularTransfer.h"
#include "../models/transactions/AccountManaging.h"
#include "../models/Bank.h"
#include "../exceptions/ATMException.h"
#include "../controllers/DBConnection.h"
#include "../constants/ATMTypes.h"

//void AccountActions::makeTransaction(Account & acc, const Transaction & tr) {
//    try {
//        const char *url = ("mysqlx://root:qwerty@91.196.194.253:33060");
//        mysqlx::Session session(url);
//        mysqlx::Schema db = session.getSchema("moop");
//        mysqlx::Table myTable = db.getTable("Transactions");
//        mysqlx::Table tableAcc = db.getTable("Account");
//
//        if (const auto* t = dynamic_cast<const OneTimeTransfer*>(&tr)){
//            if (!(t->getTo().getIBAN_() == acc.getIBAN_())){
//                tableAcc.update().set("money_", acc.getMoney()-t->getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", acc.getIBAN_()).execute();
//                acc.setMoney(acc.getMoney()-t->getAmount());
//                tableAcc.update().set("money_", t->getTo().getMoney()+t->getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", t->getTo().getIBAN_()).execute();
//
//            }
//            myTable.insert("time_", "from_", "to_", "amount_")
//                    .values(QDateTime::currentDateTime().date().toString(Qt::ISODate).toStdString(), acc.getIBAN_(), t->getTo().getIBAN_(), t->getAmount()).execute();
//        } else if (const auto* t = dynamic_cast<const RegularTransfer*>(&tr)){
//            if (!(t->getTo().getIBAN_() == acc.getIBAN_())){
//                tableAcc.update().set("money_", acc.getMoney()-t->getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", acc.getIBAN_()).execute();
//                acc.setMoney(acc.getMoney()-t->getAmount());
//                tableAcc.update().set("money_", t->getTo().getMoney()+t->getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", t->getTo().getIBAN_()).execute();
//            }
//            myTable.insert("time_", "from_", "to_", "amount_", "regularity_")
//                    .values(QDateTime::currentDateTime().date().toString(Qt::ISODate).toStdString(), acc.getIBAN_(), t->getTo().getIBAN_(), t->getAmount(), t->getRegularity()).execute();
//        }else if (const auto* t = dynamic_cast<const AccountManaging*>(&tr)){
//            switch (t->getValueType()) {
//                case AccountManaging::PIN:
//                    mysqlx::Table tableCard = db.getTable("DebitCard");
//                    tableCard.update().set("PIN_", t->getNewValue()).where("cardNum_ like :cardNum_").bind("cardNum_", t->getCardNum()).execute();
//                    myTable.insert("time_", "from_", "valueChanged_", "oldValue_", "newValue_")
//                            .values(QDateTime::currentDateTime().date().toString(Qt::ISODate).toStdString(), acc.getIBAN_(), 0, t->getOldValue(), t->getNewValue()).execute();
//                    break;
//            }
//
//        } else if (const auto* t = dynamic_cast<const CashTransaction*>(&tr)){
//            if (t->getIsWithdrawal()){
//                tableAcc.update().set("money_", acc.getMoney()-t->getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", acc.getIBAN_()).execute();
//                acc.setMoney(acc.getMoney()-t->getAmount());
//            } else{
//                tableAcc.update().set("money_", acc.getMoney()+t->getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", acc.getIBAN_()).execute();
//                acc.setMoney(acc.getMoney()+t->getAmount());
//            }
//
//            myTable.insert("time_", "from_", "amount_", "isWithdrawal_")
//                    .values(QDateTime::currentDateTime().date().toString(Qt::ISODate).toStdString(), acc.getIBAN_(), t->getAmount(), t->getIsWithdrawal()).execute();
//        }
//    } catch (std::exception& e) {
//        throw DBException(e.what());
//    }
//}

QList<Transaction*> AccountActions::viewHistory(const Account & acc) {
    CARD_NUMBER_T card_n;
    QList<Transaction*> transactions;
    try {
        DBConnection connection;
        mysqlx::Table myTable = connection.getTable("Transactions");
        mysqlx::RowResult myResult = myTable.select("id","time_","from_","to_",	"amount_",	"regularity_",	"isWithdrawal_",	"valueChanged_",	"oldValue_",	"newValue_")
                .where("from_ like :from_")
                .bind("from_",acc.getIBAN_()).execute();

        int num = myResult.count();
        for(size_t i = 0; i< num; ++i){
            mysqlx::Row row = myResult.fetchOne();
            int id (row[0].get<int>());
            std::stringstream s;
            s << row[1];
            QStringList date(QString(QString::fromStdString(s.str())).split("-"));
            QDateTime dateTime_(QDateTime::fromString(QString::fromStdString(s.str()),Qt::ISODate));

            std::stringstream IBAN1;
            IBAN1 << row[2];
            Account* from_ = Bank::getAccount(IBAN1.str());

            if(!row[5].isNull()){
                std::stringstream IBAN2;
                IBAN2 << row[3];
                Account* to_ = Bank::getAccount(IBAN2.str());

                int amount_(row[4].get<int>());
                int regularity_(row[5].get<int>());
                transactions.append(new RegularTransfer(dateTime_, *to_, *from_, amount_, regularity_));
                continue;
            }
            if (!row[6].isNull()){
                bool isWithdrawal_(row[6].get<bool>());
                int amount_(row[4].get<int>());
                transactions.append(new CashTransaction(dateTime_, *from_, amount_, isWithdrawal_));
                continue;
            }
            if (!row[7].isNull()){
                int valueChanged_(row[7].get<int>());
                unsigned __int64 oldValue_(row[8].get<int>());
                unsigned __int64 newValue_(row[9].get<int>());
                transactions.append(new AccountManaging(dateTime_, *from_, card_n, AccountManaging::ValueChanged(valueChanged_), oldValue_, newValue_));
                continue;
            }
            std::stringstream IBAN2;
            IBAN2 << row[3];
            Account* to_ = Bank::getAccount(IBAN2.str());

            int amount_(row[4].get<int>());
            transactions.append(new OneTimeTransfer(dateTime_, *to_, *from_, amount_));
        }
    } catch (std::exception& e) {
        throw DBException(e.what());
    }
    return transactions;
}


template<>
void AccountActions::makeTransaction(Account& acc, const OneTimeTransfer & t) {
    try {
        DBConnection connection;
        mysqlx::Table myTable = connection.getTable("Transactions");
        mysqlx::Table tableAcc = connection.getTable("Account");

        if (!(t.getTo().getIBAN_() == acc.getIBAN_())){
            tableAcc.update().set("money_", acc.getMoney()-t.getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", acc.getIBAN_()).execute();
            acc.setMoney(acc.getMoney()-t.getAmount());
            tableAcc.update().set("money_", t.getTo().getMoney()+t.getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", t.getTo().getIBAN_()).execute();

        }
        myTable.insert("time_", "from_", "to_", "amount_")
                .values(QDateTime::currentDateTime().toString(Qt::ISODate).toStdString(), acc.getIBAN_(), t.getTo().getIBAN_(), t.getAmount()).execute();
    } catch (std::exception& e) {
        throw DBException(e.what());
    }
}

template<>
void AccountActions::makeTransaction(Account& acc, const AccountManaging & t) {
    try{
        DBConnection connection;
        mysqlx::Table myTable = connection.getTable("Transactions");
        mysqlx::Table tableAcc = connection.getTable("Account");
        switch (t.getValueType()) {
            case AccountManaging::PIN:
                mysqlx::Table tableCard = connection.getTable("DebitCard");
                tableCard.update().set("PIN_", t.getNewValue()).where("cardNum_ like :cardNum_").bind("cardNum_", t.getCardNum()).execute();
                myTable.insert("time_", "from_", "valueChanged_", "oldValue_", "newValue_")
                        .values(QDateTime::currentDateTime().toString(Qt::ISODate).toStdString(), acc.getIBAN_(), 0, t.getOldValue(), t.getNewValue()).execute();
                break;
        }
    } catch (std::exception& e) {
        throw DBException(e.what());
    }
}
template<>
void AccountActions::makeTransaction(Account& acc, const RegularTransfer & t) {
    try{
        DBConnection connection;
        mysqlx::Table myTable = connection.getTable("Transactions");
        mysqlx::Table tableAcc = connection.getTable("Account");
        if (!(t.getTo().getIBAN_() == acc.getIBAN_())){
            tableAcc.update().set("money_", acc.getMoney()-t.getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", acc.getIBAN_()).execute();
            acc.setMoney(acc.getMoney()-t.getAmount());
            tableAcc.update().set("money_", t.getTo().getMoney()+t.getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", t.getTo().getIBAN_()).execute();
        }
        myTable.insert("time_", "from_", "to_", "amount_", "regularity_")
                .values(QDateTime::currentDateTime().toString(Qt::ISODate).toStdString(), acc.getIBAN_(), t.getTo().getIBAN_(), t.getAmount(), t.getRegularity()).execute();
    } catch (std::exception& e) {
        throw DBException(e.what());
    }
}

template<>
void AccountActions::makeTransaction(Account& acc, const CashTransaction & t) {
    try{
        DBConnection connection;
        mysqlx::Table myTable = connection.getTable("Transactions");
        mysqlx::Table tableAcc = connection.getTable("Account");

        if (t.getIsWithdrawal()){
            tableAcc.update().set("money_", acc.getMoney()-t.getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", acc.getIBAN_()).execute();
            acc.setMoney(acc.getMoney()-t.getAmount());
        } else{
            tableAcc.update().set("money_", acc.getMoney()+t.getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", acc.getIBAN_()).execute();
            acc.setMoney(acc.getMoney()+t.getAmount());
        }

        myTable.insert("time_", "from_", "amount_", "isWithdrawal_")
                .values(QDateTime::currentDateTime().toString(Qt::ISODate).toStdString(), acc.getIBAN_(), t.getAmount(), t.getIsWithdrawal()).execute();
    } catch (std::exception& e) {
        throw DBException(e.what());
    }
}

template<class T>
void AccountActions::makeTransaction(Account& acc, const T & t) {
    throw TransactionException("undefined transaction");
}