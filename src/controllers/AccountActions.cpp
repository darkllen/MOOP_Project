//
// Created by Lemonderon on 20.10.2020.
//

#include "AccountActions.h"

void AccountActions::makeTransaction(const Account & acc, const Transaction & tr) {
    //TODO: Requires implementation
}

void AccountActions::viewHistory(const Account &) {
    //TODO: Requires implementation

//    try {
//        const char *url = ("mysqlx://root:qwerty@91.196.194.253:33060");
//        mysqlx::Session session(url);
//        mysqlx::Schema db = session.getSchema("moop");
//        mysqlx::Table myTable = db.getTable("Transactions");
//        mysqlx::RowResult myResult = myTable.select("id","time_","from_","to_",	"amount_",	"regularity_",	"isWithdrawal_",	"valueChanged_",	"oldValue_",	"newValue_")
//                .where("IBAN_ like :IBAN_")
//                .bind("IBAN_",acc.getIBAN_()).execute();
//
//
//        for(size_t i = 0; i<= myResult.count(); ++i){
//            mysqlx::Row row = myResult.fetchOne();
//            int id (row[0].get<int>());
//            std::string time(row[1].get<std::string>());
//        }
//        return;
//    } catch (std::exception& e) {
//        throw DBException(e.what());
//    }
}
