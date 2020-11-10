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

bool InputValidation::validatePin(const QString &pin) {
    return pin.length() == ATMLimits::NUMBERS_IN_PIN;
}

bool InputValidation::validateCashSum(const CASH_AMOUNT_T &amount, const CARD_NUMBER_T &n) {
    Account *account = Bank::getAccount(n);
    if (const auto *t = dynamic_cast<const CheckingAccount *>(account)) {
        return amount <= t->getMoney();
    } else if (const auto *t = dynamic_cast<const SavingAccount *>(account)) {
        return amount + t->getLimit() <= t->getMoney();
    } else {
        throw TransactionException("Invalid account type");
    }
}

bool InputValidation::validateCardNumber(const CARD_NUMBER_T &n) {
    try {
        Bank::getCard(n);
        return true;
    } catch (DBException &e) {
        return false;
    }
}
