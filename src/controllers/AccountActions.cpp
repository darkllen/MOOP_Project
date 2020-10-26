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


void AccountActions::makeTransaction(const Account & acc, const Transaction & tr) {
    const char *url = ("mysqlx://root:qwerty@91.196.194.253:33060");
    mysqlx::Session session(url);
    mysqlx::Schema db = session.getSchema("moop");
    mysqlx::Table myTable = db.getTable("Transactions");
    mysqlx::Table tableAcc = db.getTable("Account");
     if (const OneTimeTransfer* t = dynamic_cast<const OneTimeTransfer*>(&tr)){
            tableAcc.update().set("money_", acc.getMoney()-t->getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", acc.getIBAN_()).execute();
            tableAcc.update().set("money_", t->getTo().getMoney()+t->getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", t->getTo().getIBAN_()).execute();
            myTable.insert("time_", "from_", "to_", "amount_")
            .values(QDateTime::currentDateTime().date().toString(Qt::ISODate).toStdString(), acc.getIBAN_(), t->getTo().getIBAN_(), t->getAmount()).execute();
     } else if (const RegularTransfer* t = dynamic_cast<const RegularTransfer*>(&tr)){
         tableAcc.update().set("money_", acc.getMoney()-t->getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", acc.getIBAN_()).execute();
         tableAcc.update().set("money_", t->getTo().getMoney()+t->getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", t->getTo().getIBAN_()).execute();
         myTable.insert("time_", "from_", "to_", "amount_", "regularity_")
                 .values(QDateTime::currentDateTime().date().toString(Qt::ISODate).toStdString(), acc.getIBAN_(), t->getTo().getIBAN_(), t->getAmount(), t->getRegularity()).execute();
     }else if (const AccountManaging* t = dynamic_cast<const AccountManaging*>(&tr)){
        //TODO add this Transaction
     } else if (const CashTransaction* t = dynamic_cast<const CashTransaction*>(&tr)){
         if (t->getIsWithdrawal()){
             tableAcc.update().set("money_", acc.getMoney()-t->getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", acc.getIBAN_()).execute();
         } else{
             tableAcc.update().set("money_", acc.getMoney()+t->getAmount()).where("IBAN_ like :IBAN_").bind("IBAN_", acc.getIBAN_()).execute();
         }

         myTable.insert("time_", "from_", "amount_", "isWithdrawal_")
                 .values(QDateTime::currentDateTime().date().toString(Qt::ISODate).toStdString(), acc.getIBAN_(), t->getAmount(), t->getIsWithdrawal()).execute();
     }
}

QList<Transaction*> AccountActions::viewHistory(const Account & acc) {
    QList<Transaction*> transactions;
    try {
        const char *url = ("mysqlx://root:qwerty@91.196.194.253:33060");
        mysqlx::Session session(url);
        mysqlx::Schema db = session.getSchema("moop");
        mysqlx::Table myTable = db.getTable("Transactions");
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
            QDate time_(date.at(0).toInt(),date.at(1).toInt(),date.at(2).toInt());

            std::stringstream IBAN1;
            IBAN1 << row[2];
            Account* from_ = Bank::getAccount(IBAN1.str());

            if(!row[5].isNull()){
                std::stringstream IBAN2;
                IBAN2 << row[3];
                Account* to_ = Bank::getAccount(IBAN2.str());

                int amount_(row[4].get<int>());
                int regularity_(row[5].get<int>());
                transactions.append(new RegularTransfer(QDateTime(time_), *to_, *from_, amount_, regularity_));
                continue;
            }
            if (!row[6].isNull()){
                bool isWithdrawal_(row[6].get<bool>());
                int amount_(row[4].get<int>());
                transactions.append(new CashTransaction(QDateTime(time_), *from_, amount_, isWithdrawal_));
                continue;
            }
            if (!row[7].isNull()){
                int valueChanged_(row[7].get<int>());
                unsigned __int64 oldValue_(row[8].get<int>());
                unsigned __int64 newValue_(row[9].get<int>());
                transactions.append(new AccountManaging(QDateTime(time_), *from_, AccountManaging::ValueChanged(valueChanged_), oldValue_, newValue_));
                continue;
            }
            std::stringstream IBAN2;
            IBAN2 << row[3];
            Account* to_ = Bank::getAccount(IBAN2.str());

            int amount_(row[4].get<int>());
            transactions.append(new OneTimeTransfer(QDateTime(time_), *to_, *from_, amount_));
        }
    } catch (std::exception& e) {
        throw DBException(e.what());
    }
    return transactions;
}
