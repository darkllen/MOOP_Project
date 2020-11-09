//
// Created by Lemonderon on 27.10.2020.
//

#ifndef ATM_VIEWS_H
#define ATM_VIEWS_H

enum ScreenEnum {
    WelcomeScreen,
    PINEnteringScreen,
    MainMenuScreen,
    FinishAccountScreen,
    CardBalanceScreen,
    TransactionHistoryScreen,
    ChangePinScreen,
    DoTransactionScreen,
    PutCashScreen,
    ShowAccountsScreen,
    TakeCashScreen,
    PoweredOffScreen,
    PutCashMScreen,
    TakeCashMScreen,
    ChangeStatusScreen,
    InfoScreen,
    CardIsInvalidScreen,
    CardIsBlockedScreen,
    ReadAmountScreen,
    ReadCardScreen,
    ReadRegScreen,
    ProcessScreen,
    ReceiptScreen
};

class QWebEngineView;

template<typename Derived>
class Screen {
protected:
    QWebEngineView *engineView;
public:
    ScreenEnum type;
    explicit Screen(ScreenEnum t, QWebEngineView &view) : type(t), engineView(&view) {}
    virtual ~Screen() = default;
    virtual void loadIntoDisplay() = 0;

    Derived *getDerived() {
        return self();
    }
private:
    Derived *self() {
        return static_cast<Derived *>(this);
    }
};

struct WelcomeScreen : public Screen {
    explicit WelcomeScreen(QWebEngineView &v) : Screen(ScreenEnum::WelcomeScreen, v) {}
    ~WelcomeScreen() override = default;
    void loadIntoDisplay() override;
};

struct PINEnteringScreen : public Screen {
    explicit PINEnteringScreen(QWebEngineView &v) : Screen(ScreenEnum::PINEnteringScreen, v) {}
    ~PINEnteringScreen() override = default;
    void loadIntoDisplay() override;

    void emptyText();
    void triesLeftUpdate(unsigned char triesLeft);
};

struct MainMenuScreen : public Screen {
    explicit MainMenuScreen(QWebEngineView &v) : Screen(ScreenEnum::MainMenuScreen, v) {}
    ~MainMenuScreen() override = default;
    void loadIntoDisplay() override;
};

struct FinishAccountScreen : public Screen {
    explicit FinishAccountScreen(QWebEngineView &v) : Screen(ScreenEnum::FinishAccountScreen, v) {}
    ~FinishAccountScreen() override = default;
    void loadIntoDisplay() override;
};

struct CardBalanceScreen : public Screen {
    explicit CardBalanceScreen(QWebEngineView &v) : Screen(ScreenEnum::CardBalanceScreen, v) {}
    ~CardBalanceScreen() override = default;
    void loadIntoDisplay() override;
};

struct TransactionHistoryScreen : public Screen {
    explicit TransactionHistoryScreen(QWebEngineView &v) : Screen(ScreenEnum::TransactionHistoryScreen, v) {}
    ~TransactionHistoryScreen() override = default;
    void loadIntoDisplay() override;
};

struct ChangePinScreen : public Screen {
    explicit ChangePinScreen(QWebEngineView &v) : Screen(ScreenEnum::ChangePinScreen, v) {}
    ~ChangePinScreen() override = default;
    void loadIntoDisplay() override;
};

struct DoTransactionScreen : public Screen {
    explicit DoTransactionScreen(QWebEngineView &v) : Screen(ScreenEnum::DoTransactionScreen, v) {}
    ~DoTransactionScreen() override = default;
    void loadIntoDisplay() override;
};

struct PutCashScreen : public Screen {
    explicit PutCashScreen(QWebEngineView &v) : Screen(ScreenEnum::PutCashScreen, v) {}
    ~PutCashScreen() override = default;
    void loadIntoDisplay() override;
};

struct ShowAccountsScreen : public Screen {
    explicit ShowAccountsScreen(QWebEngineView &v) : Screen(ScreenEnum::ShowAccountsScreen, v) {}
    ~ShowAccountsScreen() override = default;
    void loadIntoDisplay() override;
};

struct TakeCashScreen : public Screen {
    explicit TakeCashScreen(QWebEngineView &v) : Screen(ScreenEnum::TakeCashScreen, v) {}
    ~TakeCashScreen() override = default;
    void loadIntoDisplay() override;
};

struct PoweredOffScreen : public Screen {
    explicit PoweredOffScreen(QWebEngineView &v) : Screen(ScreenEnum::PoweredOffScreen, v) {}
    ~PoweredOffScreen() override = default;
    void loadIntoDisplay() override;
};

struct PutCashMScreen : public Screen {
    explicit PutCashMScreen(QWebEngineView &v) : Screen(ScreenEnum::PutCashMScreen, v) {}
    ~PutCashMScreen() override = default;
    void loadIntoDisplay() override;
};

struct TakeCashMScreen : public Screen {
    explicit TakeCashMScreen(QWebEngineView &v) : Screen(ScreenEnum::TakeCashMScreen, v) {}
    ~TakeCashMScreen() override = default;
    void loadIntoDisplay() override;
};

struct ChangeStatusScreen : public Screen {
    explicit ChangeStatusScreen(QWebEngineView &v) : Screen(ScreenEnum::ChangeStatusScreen, v) {}
    ~ChangeStatusScreen() override = default;
    void loadIntoDisplay() override;
};

struct InfoScreen : public Screen {
    explicit InfoScreen(QWebEngineView &v) : Screen(ScreenEnum::InfoScreen, v) {}
    ~InfoScreen() override = default;
    void loadIntoDisplay() override;
};

struct CardIsInvalidScreen : public Screen {
    explicit CardIsInvalidScreen(QWebEngineView &v) : Screen(ScreenEnum::CardIsInvalidScreen, v) {}
    ~CardIsInvalidScreen() override = default;
    void loadIntoDisplay() override;
};

struct CardIsBlockedScreen : public Screen {
    explicit CardIsBlockedScreen(QWebEngineView &v) : Screen(ScreenEnum::CardIsBlockedScreen, v) {}
    ~CardIsBlockedScreen() override = default;
    void loadIntoDisplay() override;
};

struct ReadAmountScreen : public Screen {
    explicit ReadAmountScreen(QWebEngineView &v) : Screen(ScreenEnum::ReadAmountScreen, v) {}
    ~ReadAmountScreen() override = default;
    void loadIntoDisplay() override;
};

struct ReadCardScreen : public Screen {
    explicit ReadCardScreen(QWebEngineView &v) : Screen(ScreenEnum::ReadCardScreen, v) {}
    ~ReadCardScreen() override = default;
    void loadIntoDisplay() override;
};

struct ReadRegScreen : public Screen {
    explicit ReadRegScreen(QWebEngineView &v) : Screen(ScreenEnum::ReadRegScreen, v) {}
    ~ReadRegScreen() override = default;
    void loadIntoDisplay() override;
};

struct ProcessScreen : public Screen {
    explicit ProcessScreen(QWebEngineView &v) : Screen(ScreenEnum::ProcessScreen, v) {}
    ~ProcessScreen() override = default;
    void loadIntoDisplay() override;
};

struct ReceiptScreen : public Screen {
    explicit ReceiptScreen(QWebEngineView &v) : Screen(ScreenEnum::ReceiptScreen, v) {}
    ~ReceiptScreen() override = default;
    void loadIntoDisplay() override;
};

#endif //ATM_VIEWS_H
