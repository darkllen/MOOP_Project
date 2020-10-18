#include <string>
class ATMInfo {
private:
	unsigned int serialNumber_;
	std::string location_;
	std::string managedBy_;
	unsigned int availiableCashAmount_;
public:
	ATMInfo(unsigned int, std::string, std::string, unsigned int);
};