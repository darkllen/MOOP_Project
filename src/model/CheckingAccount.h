#ifndef MOOP_ATM_PROJECT_ACCOUNT_H
#define MOOP_ATM_PROJECT_ACCOUNT_H
class Account;
class CheckingAccount: public Account {
public:
	CheckingAccount(const std::string&, const std::string&);
	~CheckingAccount();
};
#endif //MOOP_ATM_PROJECT_ACCOUNT_H
