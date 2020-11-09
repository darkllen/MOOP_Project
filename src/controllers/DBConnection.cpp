//
// Created by darklen on 11/9/2020.
//

#include "DBConnection.h"
mysqlx::Table DBConnection::getTable(const std::string & s) {
    mysqlx::Schema db = session.getSchema("moop");
    return db.getTable(s);
}

DBConnection::DBConnection(): session(DB::url) {
}
