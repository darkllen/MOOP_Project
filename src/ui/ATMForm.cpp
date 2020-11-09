//
// Created by Lemonderon on 02.10.2020.
//

#include <QWebChannel>
#include <QtWidgets/qabstractbutton.h>
#include <QInputDialog>
#include <QMessageBox>

#include "ATMForm.h"
#include "ui_mainwindow.h"
#include "../exceptions/ATMException.h"

ATMForm::ATMForm(QMainWindow &mw, ATMQtUiController &atm_io)
        : QWidget(), ui_(new Ui::MainWindowForm), controller_(&atm_io) {
    ui_->setupUi(&mw);
    configureSignalAndSlots();
    setMainWindowBackground(mw);
    initValues();
}

//TODO why only one pointer field is deleted?
ATMForm::~ATMForm() {
    delete ui_;
}

void ATMForm::configureSignalAndSlots() {
    connect(ui_->n000_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n000_keypad_btn_clicked);
    connect(ui_->n0_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n0_keypad_btn_clicked);
    connect(ui_->n1_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n1_keypad_btn_clicked);
    connect(ui_->n2_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n2_keypad_btn_clicked);
    connect(ui_->n3_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n3_keypad_btn_clicked);
    connect(ui_->n4_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n4_keypad_btn_clicked);
    connect(ui_->n5_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n5_keypad_btn_clicked);
    connect(ui_->n6_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n6_keypad_btn_clicked);
    connect(ui_->n7_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n7_keypad_btn_clicked);
    connect(ui_->n8_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n8_keypad_btn_clicked);
    connect(ui_->n9_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n9_keypad_btn_clicked);
    connect(ui_->dot_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_dot_keypad_btn_clicked);
    connect(ui_->cancel_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_cancel_keypad_btn_clicked);
    connect(ui_->clear_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_clear_keypad_btn_clicked);
    connect(ui_->enter_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_enter_keypad_btn_clicked);
    connect(ui_->empty_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_empty_keypad_btn_clicked);

    connect(ui_->receipt_btn, &QPushButton::clicked, this, &ATMForm::on_receipt_btn_clicked);
    connect(ui_->card_reader_btn, &QPushButton::clicked, this, &ATMForm::on_card_reader_btn_clicked);
    connect(ui_->dispenser_btn, &QPushButton::clicked, this, &ATMForm::on_dispenser_btn_clicked);

    connect(ui_->d0r_btn, &QPushButton::clicked, this, &ATMForm::on_d0r_btn_clicked);
    connect(ui_->d1r_btn, &QPushButton::clicked, this, &ATMForm::on_d1r_btn_clicked);
    connect(ui_->d2r_btn, &QPushButton::clicked, this, &ATMForm::on_d2r_btn_clicked);
    connect(ui_->d3r_btn, &QPushButton::clicked, this, &ATMForm::on_d3r_btn_clicked);

    connect(ui_->d0l_btn, &QPushButton::clicked, this, &ATMForm::on_d0l_btn_clicked);
    connect(ui_->d1l_btn, &QPushButton::clicked, this, &ATMForm::on_d1l_btn_clicked);
    connect(ui_->d2l_btn, &QPushButton::clicked, this, &ATMForm::on_d2l_btn_clicked);
    connect(ui_->d3l_btn, &QPushButton::clicked, this, &ATMForm::on_d3l_btn_clicked);

    connect(ui_->actionExit, &QAction::triggered, this, &ATMForm::on_exit_action_triggered);
    connect(ui_->actionPowerOn, &QAction::triggered, this, &ATMForm::on_powerOn_action_triggered);
    connect(ui_->actionPowerOff, &QAction::triggered, this, &ATMForm::on_powerOff_action_triggered);
}

void ATMForm::initValues() {
    ui_->dispenser_btn->setEnabled(false);
    ui_->receipt_btn->setEnabled(false);
}


void ATMForm::setMainWindowBackground(QMainWindow &mw) {
    mw.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    QPixmap background(":/green_background.png");
    background = background.scaled(mw.size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    mw.setPalette(palette);
}

void ATMForm::on_n000_keypad_btn_clicked() {
    controller_->dialPadInput(UIButtonsInput::DialPad::D000);
}

void ATMForm::on_n0_keypad_btn_clicked() {
    controller_->dialPadInput(UIButtonsInput::DialPad::D0);
}

void ATMForm::on_n1_keypad_btn_clicked() {
    controller_->dialPadInput(UIButtonsInput::DialPad::D1);
}

void ATMForm::on_n2_keypad_btn_clicked() {
    controller_->dialPadInput(UIButtonsInput::DialPad::D2);
}

void ATMForm::on_n3_keypad_btn_clicked() {
    controller_->dialPadInput(UIButtonsInput::DialPad::D3);
}

void ATMForm::on_n4_keypad_btn_clicked() {
    controller_->dialPadInput(UIButtonsInput::DialPad::D4);
}

void ATMForm::on_n5_keypad_btn_clicked() {
    controller_->dialPadInput(UIButtonsInput::DialPad::D5);
}

void ATMForm::on_n6_keypad_btn_clicked() {
    controller_->dialPadInput(UIButtonsInput::DialPad::D6);
}

void ATMForm::on_n7_keypad_btn_clicked() {
    controller_->dialPadInput(UIButtonsInput::DialPad::D7);
}

void ATMForm::on_n8_keypad_btn_clicked() {
    controller_->dialPadInput(UIButtonsInput::DialPad::D8);
}

void ATMForm::on_n9_keypad_btn_clicked() {
    controller_->dialPadInput(UIButtonsInput::DialPad::D9);
}

void ATMForm::on_dot_keypad_btn_clicked() {
    controller_->dialPadInput(UIButtonsInput::DialPad::DDot);
}

void ATMForm::on_cancel_keypad_btn_clicked() {
    controller_->dialPadControlInput(UIButtonsInput::ControlPad::Cancel);
}

void ATMForm::on_clear_keypad_btn_clicked() {
    controller_->dialPadControlInput(UIButtonsInput::ControlPad::Clear);
}

void ATMForm::on_enter_keypad_btn_clicked() {
    controller_->dialPadControlInput(UIButtonsInput::ControlPad::Enter);
}

void ATMForm::on_empty_keypad_btn_clicked() {
    controller_->dialPadControlInput(UIButtonsInput::ControlPad::Empty);
}

void ATMForm::on_receipt_btn_clicked() {
    controller_->printReceiptOutput();
}

void ATMForm::on_card_reader_btn_clicked() {
//    if (cardReaderStateIsInsert) {
    bool ok;
    QString text = QInputDialog::getText(nullptr, "Card reader input dialog",
                                         "Please enter your card number:", QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty()) {
        bool convertSuccess;
        CARD_NUMBER_T value = text.toULongLong(&convertSuccess, 10);
        if (convertSuccess) {
            controller_->cardReaderInput(value);
            changeCardReader(false);
        } else {
            QMessageBox::warning(nullptr, "Invalid input", "Card number is invalid!", QMessageBox::Ok);
        }
    }
//    } else {
//        //TODO: Needs implementation
//    }
}

void ATMForm::on_dispenser_btn_clicked() {
    if (ui_->dispenser_btn->isEnabled()) {
        if (isWithdrawal) {
            bool ok;
            QString text = QInputDialog::getText(nullptr, "Dispenser input dialog",
                                                 "Please input cash amount to take:", QLineEdit::Normal,
                                                 "", &ok);
            if (ok && !text.isEmpty()) {
                bool convertSuccess;
                CASH_AMOUNT_T value = text.toULongLong(&convertSuccess, 10);
                if (convertSuccess) {
                    try {
                        controller_->dispenserOutput(value);
                        changeDispenser(false);
                        if (controller_->getIsOn()) {
                            controller_->navigateToNewView(MainMenuScreen);
                            changeReceipt(true);
                        } else
                            controller_->navigateToNewView(PoweredOffScreen);
                    }
                    catch (const TransactionException &e) {
                        controller_->changeWarning(e.what());
                    }
                    catch (const HardwareException &e) {
                        controller_->changeWarning(e.what());
                    }
                } else {
                    controller_->changeWarning("Cash amount is invalid");
                }
            }
        } else {
            bool ok;
            QString text = QInputDialog::getText(nullptr, "Dispenser input dialog",
                                                 "Please input cash amount to put in dispenser:", QLineEdit::Normal,
                                                 "", &ok);
            if (ok && !text.isEmpty()) {
                bool convertSuccess;
                CASH_AMOUNT_T value = text.toULongLong(&convertSuccess, 10);
                if (convertSuccess) {
                    try {
                        controller_->dispenserInput(value);
                        changeDispenser(false);
                        if (controller_->getIsOn()) {
                            controller_->navigateToNewView(MainMenuScreen);
                            changeReceipt(true);
                        } else
                            controller_->navigateToNewView(PoweredOffScreen);
                    }
                    catch (const TransactionException &e) {
                        controller_->changeWarning(e.what());
                    }
                    catch (const HardwareException &e) {
                        controller_->changeWarning(e.what());
                    }
                } else {
                    controller_->changeWarning("Cash amount is invalid");
                }
            }

        }

    }
}

void ATMForm::on_d0r_btn_clicked() {
    controller_->sideDisplayBtnInput(UIButtonsInput::DisplaySideButton::R0);
}

void ATMForm::on_d1r_btn_clicked() {
    controller_->sideDisplayBtnInput(UIButtonsInput::DisplaySideButton::R1);
}

void ATMForm::on_d2r_btn_clicked() {
    controller_->sideDisplayBtnInput(UIButtonsInput::DisplaySideButton::R2);
}

void ATMForm::on_d3r_btn_clicked() {
    controller_->sideDisplayBtnInput(UIButtonsInput::DisplaySideButton::R3);
}

void ATMForm::on_d0l_btn_clicked() {
    controller_->sideDisplayBtnInput(UIButtonsInput::DisplaySideButton::L0);
}

void ATMForm::on_d1l_btn_clicked() {
    controller_->sideDisplayBtnInput(UIButtonsInput::DisplaySideButton::L1);
}

void ATMForm::on_d2l_btn_clicked() {
    controller_->sideDisplayBtnInput(UIButtonsInput::DisplaySideButton::L2);
}

void ATMForm::on_d3l_btn_clicked() {
    controller_->sideDisplayBtnInput(UIButtonsInput::DisplaySideButton::L3);
}

void ATMForm::on_powerOn_action_triggered() {
    controller_->ATMPowerChangeFromUI(ATMPowerState::On);
}

void ATMForm::on_powerOff_action_triggered() {
    controller_->ATMPowerChangeFromUI(ATMPowerState::Off);
}

QWebEngineView &ATMForm::getWebView() {
    return *(ui_->display);
}

//TODO function is never used
void ATMForm::toggleCardReaderMode() {
    cardReaderStateIsInsert = !cardReaderStateIsInsert;
    if (cardReaderStateIsInsert) {
        //Todo: fix
        ui_->card_reader_btn->setText("Insert card");
        ui_->card_reader_btn->setText("Get back card");
    }
}

void ATMForm::changeDispenser(bool b) {
    ui_->dispenser_btn->setEnabled(b);
}

void ATMForm::changeCardReader(bool b) {
    ui_->card_reader_btn->setEnabled(b);
}

void ATMForm::changeReceipt(bool b) {
    ui_->receipt_btn->setEnabled(b);
}

bool ATMForm::getIsReceiptEnable() {
    return ui_->receipt_btn->isEnabled();
}

void ATMForm::setIsWithdrawal(bool b) {
    isWithdrawal = b;
}

void ATMForm::on_exit_action_triggered() {
    QApplication::exit();
}



