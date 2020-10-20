#ifndef MOOP_ATM_PROJECT_SESSIONMANAGER_H
#define MOOP_ATM_PROJECT_SESSIONMANAGER_H

#include <QtCore/QDateTime>

class QDateTime;

class SessionManager {
private:

    QDateTime lastActionTime_;

public:
    explicit SessionManager();
    ~SessionManager() = default;

    bool checkExpiration();
    //update to current date and time
    void updateLastActionTime();
};

#endif //MOOP_ATM_PROJECT_SESSIONMANAGER_H
