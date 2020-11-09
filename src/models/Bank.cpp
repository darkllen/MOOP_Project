//
// Created by Lemonderon on 20.10.2020.
//

#include "Bank.h"

#include "../exceptions/ATMException.h"
#include <string>
#include "DebitCard.h"
#include "accounts/Account.h"
#include "accounts/CheckingAccount.h"
#include "accounts/SavingAccount.h"
#include "Customer.h"
#include "../controllers/DBConnection.h"

Bank::Bank(const BANK_NUMBER_T& id, std::string address, std::string name) :
        id_(id), address_(std::move(address)),
        name_(std::move(name)) {}

DebitCard Bank::getCard(const CARD_NUMBER_T& cardNumberT) {
    try {
        DBConnection connection;
        mysqlx::Table myTable = connection.getTable("DebitCard");
        mysqlx::RowResult myResult = myTable.select("expireDate_","cvCode_","PIN_",	"isBlocked_")
                .where("cardNum_ like :cardNum_")
                .bind("cardNum_",cardNumberT).execute();

        if (myResult.count() == 0){
            throw DBException("no card was found");
        }
        mysqlx::Row row = myResult.fetchOne();
        std::stringstream s;
        s << row[0];
        QStringList date(QString(QString::fromStdString(s.str())).split("-"));
        QDate expireDate_(date.at(0).toInt(),date.at(1).toInt(),date.at(2).toInt());
        CVV_T cvCode_(row[1].get<int>());
        CVV_T PIN_(row[2].get<int>());
        bool isBlocked_(row[3].get<bool>());
        return DebitCard(cardNumberT, QDateTime(expireDate_), cvCode_, PIN_, isBlocked_);
    } catch (std::exception& e) {
        throw DBException(e.what());
    }
}

Account* Bank::getAccount(const std::string & IBAN_) {
    try {
        DBConnection connection;
        mysqlx::Table myTable = connection.getTable("Account");
        mysqlx::RowResult myResult = myTable.select("ownerId_","bank_id","limit_",	"interestRate_", "money_")
                .where("IBAN_ like :IBAN_")
                .bind("IBAN_",IBAN_).execute();

        mysqlx::Row row = myResult.fetchOne();
        int ownerId_ = row.get(0).get<int>();
        BANK_NUMBER_T bankNumberT(row.get(1).get<int>());
        int money(row.get(4).get<int>());
        if (row[2].isNull()) return new CheckingAccount(ownerId_, IBAN_, bankNumberT, money);
        unsigned int limit_(row[2].get<unsigned int>());
        float interestRate_(row[3].get<double>());
        return new SavingAccount(ownerId_, IBAN_, bankNumberT, limit_, interestRate_, money);
    } catch (std::exception& e) {
        throw DBException(e.what());
    }
}

Account* Bank::getAccount(const CARD_NUMBER_T& cardNumberT) {
    DBConnection connection;
    mysqlx::Table myTable = connection.getTable("DebitCard");
    mysqlx::RowResult myResult = myTable.select("accountIBAN")
            .where("cardNum_ like :cardNum_")
            .bind("cardNum_",cardNumberT).execute();

    mysqlx::Row rowIBAN = myResult.fetchOne();
    std::stringstream s;
    s << rowIBAN[0];
    return getAccount(s.str());
}

Customer* Bank::getCustomer(const CARD_NUMBER_T& num){
    int id = getAccount(num)->getOwnerId();
    DBConnection connection;
    mysqlx::Table myTable = connection.getTable("Сustomer");
    mysqlx::RowResult myResult = myTable.select("name_", "address")
            .where("id like :idd")
            .bind("idd",id).execute();


    mysqlx::Row rowCustomer = myResult.fetchOne();
    std::stringstream n;
    n << rowCustomer[0];
    std::string name(n.str());
    std::stringstream ad;
    ad << rowCustomer[1];
    std::string address(ad.str());

    return new Customer(name, address);
}

