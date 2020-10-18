class DebitCard;
class CardPinCheck {
private:
	size_t enteringTriesPINNum_;
public :
	CardPinCheck();
	bool checkPin(const unsigned int&, const size_t&);
};