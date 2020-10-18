class Account;
class SavingAccount : public Account {
private:
	unsigned int limit_;
	double interestRate_;
public:
	SavingAccount(const std::string&, const std::string&, const unsigned int&, const double&);
};