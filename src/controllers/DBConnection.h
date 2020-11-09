//
// Created by darklen on 11/9/2020.
//

#ifndef ATM_DBCONNECTION_H
#define ATM_DBCONNECTION_H

#include "mysqlx/xdevapi.h"


namespace DB{
    static const char *url = "mysqlx://root:qwerty@91.196.194.253:33060";
}
class DBConnection {
private:
    mysqlx::Session session;
public:
    DBConnection();
    mysqlx::Table getTable(const std::string&);
};


#endif //ATM_DBCONNECTION_H
