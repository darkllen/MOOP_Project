//
// Created by anna2 on 25.10.2020.
//

#include <QtCore/qdatetime.h>
#include "../constants/ATMTypes.h"
#include "../constants/ATMLimits.h"
#include "InputValidation.h"

#include <regex>

bool InputValidation::validatePin(PIN_T pin){
    return pin < pow(10, ATMLimits::NUMBERS_IN_PIN);
}

bool InputValidation::validateTimePeriod(const QDateTime &begin, const QDateTime &end){
    return begin<end;
}

bool InputValidation::validateCashSum(CASH_AMOUNT_T amount){
    return amount>0;
}

bool InputValidation::validatePersonName(QString &s){
    std::regex nameSurnameRegex("[a-zA-Z]{2,}\\s[a-zA-Z]{1,}'?-?[a-zA-Z]{2,}\\s?([a-zA-Z]{1,})?)");
    return std::regex_match (s.toStdString(),nameSurnameRegex);
}

bool InputValidation::validateCardNumber(CARD_NUMBER_T){
    //todo check that card number exists in db
    return true;
}
