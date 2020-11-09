//
// Created by darklen on 11/6/2020.
//
#include "DebitCard.h"
#include "../controllers/DBConnection.h"

void DebitCard::setIsBlocked(bool value) {
    DBConnection connection;
    mysqlx::Table myTable = connection.getTable("Transactions");
    mysqlx::Table tableCard = connection.getTable("DebitCard");
    tableCard.update().set("isBlocked_", value).where("cardNum_ like :cardNum_").bind("cardNum_", cardNum_).execute();
}

