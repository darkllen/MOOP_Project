#include <string>
class Account {
private:
	std::string ownerName_;
	std::string IBAN_;
public:
	Account(const std::string&, const std::string&);
	size_t getCardPIN();
	size_t getBank();
};