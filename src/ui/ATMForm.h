//
// Created by Lemonderon on 02.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMFORM_H
#define MOOP_ATM_PROJECT_ATMFORM_H

#include <QWidget>
#include <QMainWindow>
#include <QtWebEngineWidgets/QWebEngineView>

#include "../models/ATM.h"
#include "../controllers/ui/ATMQtUiController.h"

namespace Ui {
    class MainWindowForm;
}

class ATMForm : public QWidget {
Q_OBJECT

private:
    void configureSignalAndSlots();
    void setMainWindowBackground(QMainWindow &mw);

    Ui::MainWindowForm *ui_;
    ATMQtUiController *controller_;

public:
    explicit ATMForm(QMainWindow &mw, ATMQtUiController &atm_io);
    ~ATMForm() override;

    QWebEngineView &getWebView();

private slots:
    void on_n000_keypad_btn_clicked();
    void on_n0_keypad_btn_clicked();
    void on_n1_keypad_btn_clicked();
    void on_n2_keypad_btn_clicked();
    void on_n3_keypad_btn_clicked();
    void on_n4_keypad_btn_clicked();
    void on_n5_keypad_btn_clicked();
    void on_n6_keypad_btn_clicked();
    void on_n7_keypad_btn_clicked();
    void on_n8_keypad_btn_clicked();
    void on_n9_keypad_btn_clicked();
    void on_dot_keypad_btn_clicked();

    void on_cancel_keypad_btn_clicked();
    void on_clear_keypad_btn_clicked();
    void on_enter_keypad_btn_clicked();
    void on_empty_keypad_btn_clicked();

    void on_receipt_btn_clicked();
    void on_card_reader_btn_clicked();
    void on_dispenser_btn_clicked();

    void on_d0r_btn_clicked();
    void on_d1r_btn_clicked();
    void on_d2r_btn_clicked();
    void on_d3r_btn_clicked();

    void on_d0l_btn_clicked();
    void on_d1l_btn_clicked();
    void on_d2l_btn_clicked();
    void on_d3l_btn_clicked();

    void on_powerOn_action_triggered();
    void on_powerOff_action_triggered();
};

#endif //MOOP_ATM_PROJECT_ATMFORM_H
