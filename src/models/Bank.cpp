//
// Created by Lemonderon on 20.10.2020.
//

#include "Bank.h"

#include "../exceptions/ATMException.h"
#include <mysqlx/xdevapi.h>
#include <string>

Bank::Bank(BANK_NUMBER_T id, std::string address, std::string name) :
        id_(id), address_(std::move(address)),
        name_(std::move(name)) {}

PIN_T Bank::getCardPIN(const CARD_NUMBER_T & cardNumberT) {
    try {
        const char *url = ("mysqlx://root:qwerty@91.196.194.253:33060");
        mysqlx::Session session(url);
        mysqlx::Schema db = session.getSchema("moop");
        mysqlx::Table myTable = db.getTable("DebitCard");
        mysqlx::RowResult myResult = myTable.select("PIN_")
                .where("cardNum_ like :cardNum_")
                .bind("cardNum_",cardNumberT).execute();
        mysqlx::Row row = myResult.fetchOne();
        return row.get(0).get<int>();
    } catch (std::exception& e) {
        throw DBException(e.what());
    }
}
