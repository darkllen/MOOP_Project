#include <string>
class Account {
private:
	std::string ownerName_;
	std::string IBAN_;
public:
	Account(std::string, std::string);
	size_t getCardPIN();
	size_t getBank();
};