//
// Created by darklen on 11/6/2020.
//
#include "mysqlx/xdevapi.h"
#include "DebitCard.h"

void DebitCard::setIsBlocked(bool value) {
    const char *url = ("mysqlx://root:qwerty@91.196.194.253:33060");
    mysqlx::Session session(url);
    mysqlx::Schema db = session.getSchema("moop");
    mysqlx::Table myTable = db.getTable("Transactions");
    mysqlx::Table tableCard = db.getTable("DebitCard");

    tableCard.update().set("isBlocked_", value).where("cardNum_ like :cardNum_").bind("cardNum_", cardNum_).execute();
}

