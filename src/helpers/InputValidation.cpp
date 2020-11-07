//
// Created by anna2 on 25.10.2020.
//

#include <QtCore/qdatetime.h>
#include "../constants/ATMTypes.h"
#include "../constants/ATMLimits.h"
#include "../models/Bank.h"
#include "../models/DebitCard.h"
#include "../models/accounts/Account.h"
#include "../exceptions/ATMException.h"
#include "InputValidation.h"
#include "../models/accounts/CheckingAccount.h"
#include "../models/accounts/SavingAccount.h"

#include <regex>

bool InputValidation::validatePin(PIN_T pin){
    return pin < pow(10, ATMLimits::NUMBERS_IN_PIN);
}

bool InputValidation::validateTimePeriod(const QDateTime &begin, const QDateTime &end){
    return begin<end;
}

bool InputValidation::validateCashSum(CASH_AMOUNT_T amount, CARD_NUMBER_T n){
    //todo check limit in sav acc
    try {
        Account* account = Bank::getAccount(n);
        if (const auto* t = dynamic_cast<const CheckingAccount*>(account)) {
            return amount <= t->getMoney();
        } else if (const auto* t = dynamic_cast<const SavingAccount*>(account)){
            return amount + t->getLimit()<= t->getMoney();

        } else throw TransactionException("Wrong account type");


} catch (DBException& e) {
        return false;
    }
}

bool InputValidation::validatePersonName(QString &s){
    std::regex nameSurnameRegex("[a-zA-Z]{2,}\\s[a-zA-Z]{1,}'?-?[a-zA-Z]{2,}\\s?([a-zA-Z]{1,})?)");
    return std::regex_match (s.toStdString(),nameSurnameRegex);
}

bool InputValidation::validateCardNumber(CARD_NUMBER_T n){
    try {
        Bank::getCard(n);
        return true;
    } catch (DBException& e) {
        return false;
    }
}
