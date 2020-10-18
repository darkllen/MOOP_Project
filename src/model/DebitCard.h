#ifndef MOOP_ATM_PROJECT_DEBITCARD_H
#define MOOP_ATM_PROJECT_DEBITCARD_H
#include <ctime>
class DebitCard {
private:
	unsigned int cardNum_;
	time_t expireDate_;
	size_t cvCode_;
	size_t PIN_;

public:
	DebitCard(const unsigned int&, const time_t&, const size_t&, const size_t&);
	~DebitCard();
};
#endif //MOOP_ATM_PROJECT_DEBITCARD_H
