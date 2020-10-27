//
// Created by Lemonderon on 02.10.2020.
//

#include <QWebChannel>
#include <QtWidgets/qabstractbutton.h>
#include <QInputDialog>
#include <QMessageBox>

#include "ATMForm.h"
#include "ui_mainwindow.h"
#include "../events/UIInput.h"
#include "../constants/ATMTypes.h"

ATMForm::ATMForm(QMainWindow &mw, ATMQtUiController &atm_io)
        : QWidget(), ui_(new Ui::MainWindowForm), controller_(&atm_io) {
    ui_->setupUi(&mw);
    configureSignalAndSlots();
    setMainWindowBackground(mw);
    initValues();
}

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
    controller_->dialPadInput(UIInput::DialPadBtnInput::D000);
}

void ATMForm::on_n0_keypad_btn_clicked() {
    controller_->dialPadInput(UIInput::DialPadBtnInput::D0);
}

void ATMForm::on_n1_keypad_btn_clicked() {
    controller_->dialPadInput(UIInput::DialPadBtnInput::D1);
}

void ATMForm::on_n2_keypad_btn_clicked() {
    controller_->dialPadInput(UIInput::DialPadBtnInput::D2);
}

void ATMForm::on_n3_keypad_btn_clicked() {
    controller_->dialPadInput(UIInput::DialPadBtnInput::D3);
}

void ATMForm::on_n4_keypad_btn_clicked() {
    controller_->dialPadInput(UIInput::DialPadBtnInput::D4);
}

void ATMForm::on_n5_keypad_btn_clicked() {
    controller_->dialPadInput(UIInput::DialPadBtnInput::D5);
}

void ATMForm::on_n6_keypad_btn_clicked() {
    controller_->dialPadInput(UIInput::DialPadBtnInput::D6);
}

void ATMForm::on_n7_keypad_btn_clicked() {
    controller_->dialPadInput(UIInput::DialPadBtnInput::D7);
}

void ATMForm::on_n8_keypad_btn_clicked() {
    controller_->dialPadInput(UIInput::DialPadBtnInput::D8);
}

void ATMForm::on_n9_keypad_btn_clicked() {
    controller_->dialPadInput(UIInput::DialPadBtnInput::D9);
}

void ATMForm::on_dot_keypad_btn_clicked() {
    controller_->dialPadInput(UIInput::DialPadBtnInput::DDot);
}

void ATMForm::on_cancel_keypad_btn_clicked() {
    controller_->dialPadControlInput(UIInput::ControlBtnInput::Cancel);
}

void ATMForm::on_clear_keypad_btn_clicked() {
    controller_->dialPadControlInput(UIInput::ControlBtnInput::Clear);
}

void ATMForm::on_enter_keypad_btn_clicked() {
    controller_->dialPadControlInput(UIInput::ControlBtnInput::Enter);
}

void ATMForm::on_empty_keypad_btn_clicked() {
    controller_->dialPadControlInput(UIInput::ControlBtnInput::Empty);
}

void ATMForm::on_receipt_btn_clicked() {
    qDebug() << "get receipt";
    //TODO: Needs implementation
}

void ATMForm::on_card_reader_btn_clicked() {
    if (cardReaderStateIsInsert) {
        bool ok;
        QString text = QInputDialog::getText(nullptr, "Card reader input dialog",
                                             "Please enter your card number:", QLineEdit::Normal,
                                             "", &ok);
        if (ok && !text.isEmpty()) {
            bool convertSuccess;
            CARD_NUMBER_T value = text.toULongLong(&convertSuccess, 10);
            if (convertSuccess) {
                controller_->cardReaderInput(value);
            } else {
                QMessageBox::warning(nullptr, "Invalid input", "Card number is invalid!", QMessageBox::Ok);
            }
        }
    } else {
        //TODO: Needs implementation
    }
}

void ATMForm::on_dispenser_btn_clicked() {
    qDebug() << "dispenser";
    //TODO: Needs implementation
    controller_->dispenserInput();
}

void ATMForm::on_d0r_btn_clicked() {
    controller_->sideDisplayBtnInput(UIInput::DisplaySideBtnInput::R0);
}

void ATMForm::on_d1r_btn_clicked() {
    controller_->sideDisplayBtnInput(UIInput::DisplaySideBtnInput::R1);
}

void ATMForm::on_d2r_btn_clicked() {
    controller_->sideDisplayBtnInput(UIInput::DisplaySideBtnInput::R2);
}

void ATMForm::on_d3r_btn_clicked() {
    controller_->sideDisplayBtnInput(UIInput::DisplaySideBtnInput::R3);
}

void ATMForm::on_d0l_btn_clicked() {
    controller_->sideDisplayBtnInput(UIInput::DisplaySideBtnInput::L0);
}

void ATMForm::on_d1l_btn_clicked() {
    controller_->sideDisplayBtnInput(UIInput::DisplaySideBtnInput::L1);
}

void ATMForm::on_d2l_btn_clicked() {
    controller_->sideDisplayBtnInput(UIInput::DisplaySideBtnInput::L2);
}

void ATMForm::on_d3l_btn_clicked() {
    controller_->sideDisplayBtnInput(UIInput::DisplaySideBtnInput::L3);
}

void ATMForm::on_powerOn_action_triggered() {
    controller_->ATMPowerChange(UIInput::ATMPowerState::On);
}

void ATMForm::on_powerOff_action_triggered() {
    controller_->ATMPowerChange(UIInput::ATMPowerState::Off);
}

QWebEngineView &ATMForm::getWebView() {
    return *(ui_->display);
}

void ATMForm::toggleCardReaderMode() {
    cardReaderStateIsInsert = !cardReaderStateIsInsert;
    if (cardReaderStateIsInsert) {
        ui_->card_reader_btn->setText("Insert card");
        ui_->card_reader_btn->setText("Get back card");
    }
}
