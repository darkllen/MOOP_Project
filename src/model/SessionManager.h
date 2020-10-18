#include <ctime>
class SessionManager {
private:
	static unsigned int maxIdleTime_;
	time_t lastActionTime_;
public:
	bool checkExpiration();
	//update to current date and time
	void updateLastActionTime();
};