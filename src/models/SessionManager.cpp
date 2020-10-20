//
// Created by Lemonderon on 21.10.2020.
//

#include "SessionManager.h"
#include "../constants/ATMLimits.h"

#include <QDateTime>

SessionManager::SessionManager() : lastActionTime_(QDateTime::currentDateTime()) {}

bool SessionManager::checkExpiration() {
    QDateTime current = QDateTime::currentDateTime();
    QDateTime checkAgainst(current.addSecs(ATMLimits::MAX_SESSION_IDLE_TIME_SEC));
    return current < checkAgainst;
}

void SessionManager::updateLastActionTime() {
    lastActionTime_ = QDateTime::currentDateTime();
}
