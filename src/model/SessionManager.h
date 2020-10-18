#ifndef MOOP_ATM_PROJECT_SESSIONMANAGER_H
#define MOOP_ATM_PROJECT_SESSIONMANAGER_H
#include <ctime>
class SessionManager {
private:
	static unsigned int maxIdleTime_;
	time_t lastActionTime_;
public:
	SessionManager(time_t);
    ~SessionManager();

	bool checkExpiration();
	//update to current date and time
	void updateLastActionTime();
};
#endif //MOOP_ATM_PROJECT_SESSIONMANAGER_H
