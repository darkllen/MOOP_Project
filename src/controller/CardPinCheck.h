#ifndef MOOP_ATM_PROJECT_CARDPINCHECK_H
#define MOOP_ATM_PROJECT_CARDPINCHECK_H

class DebitCard;
class CardPinCheck {
private:
	size_t enteringTriesPINNum_;
public :
	CardPinCheck();
    ~CardPinCheck();
	bool checkPin(const unsigned int&, const size_t&);
};
#endif //MOOP_ATM_PROJECT_CARDPINCHECK_H