#ifndef MOOP_ATM_PROJECT_SESSIONMANAGER_H
#define MOOP_ATM_PROJECT_SESSIONMANAGER_H

#include <ctime>
#include <QtCore/qdatetime.h>

class SessionManager {
private:
    static unsigned int maxIdleTime_;
    QDateTime lastActionTime_;
public:
    SessionManager(time_t);
    ~SessionManager();

    bool checkExpiration();
    //update to current date and time
    void updateLastActionTime();
};

#endif //MOOP_ATM_PROJECT_SESSIONMANAGER_H
