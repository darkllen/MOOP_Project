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
        return (amount <= t->getMoney()&&(amount>0));
    } else if (const auto *t = dynamic_cast<const SavingAccount *>(account)) {
        return (amount + t->getLimit() <= t->getMoney() &&(amount>0));
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

bool InputValidation::validateSameAccount(const CARD_NUMBER_T &n, const CARD_NUMBER_T &m) {
    try {
        const Account* a1 = Bank::getAccount(n);
        const Account* a2 = Bank::getAccount(m);

        return (a1->getIBAN_() != a2->getIBAN_());
    } catch (DBException &e) {
        return false;
    }
}
