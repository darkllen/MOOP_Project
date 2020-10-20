//
// Created by Lemonderon on 02.10.2020.
//

#include <QWebChannel>
#include <QtWidgets/qabstractbutton.h>

#include "ATMForm.h"
#include "ui_mainwindow.h"

ATMForm::ATMForm(QMainWindow &mw, ATMQtUiController &atm_io) : QWidget(), ui_(new Ui::MainWindowForm), controller_(&atm_io) {
    ui_->setupUi(&mw);
    configureSignalAndSlots();
    setMainWindowBackground(mw);
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
    controller_->dialPadInput(DialPadBtn::D000);
}

void ATMForm::on_n0_keypad_btn_clicked() {
    controller_->dialPadInput(DialPadBtn::D0);
}

void ATMForm::on_n1_keypad_btn_clicked() {
    controller_->dialPadInput(DialPadBtn::D1);
}

void ATMForm::on_n2_keypad_btn_clicked() {
    controller_->dialPadInput(DialPadBtn::D2);
}

void ATMForm::on_n3_keypad_btn_clicked() {
    controller_->dialPadInput(DialPadBtn::D3);
}

void ATMForm::on_n4_keypad_btn_clicked() {
    controller_->dialPadInput(DialPadBtn::D4);
}

void ATMForm::on_n5_keypad_btn_clicked() {
    controller_->dialPadInput(DialPadBtn::D5);
}

void ATMForm::on_n6_keypad_btn_clicked() {
    controller_->dialPadInput(DialPadBtn::D6);
}

void ATMForm::on_n7_keypad_btn_clicked() {
    controller_->dialPadInput(DialPadBtn::D7);
}

void ATMForm::on_n8_keypad_btn_clicked() {
    controller_->dialPadInput(DialPadBtn::D8);
}

void ATMForm::on_n9_keypad_btn_clicked() {
    controller_->dialPadInput(DialPadBtn::D9);
}

void ATMForm::on_dot_keypad_btn_clicked() {
    controller_->dialPadInput(DialPadBtn::DDot);
}

void ATMForm::on_cancel_keypad_btn_clicked() {
    controller_->dialPadControlInput(ControlBtn::Cancel);
}

void ATMForm::on_clear_keypad_btn_clicked() {
    controller_->dialPadControlInput(ControlBtn::Clear);
}

void ATMForm::on_enter_keypad_btn_clicked() {
    controller_->dialPadControlInput(ControlBtn::Enter);
}

void ATMForm::on_empty_keypad_btn_clicked() {
    controller_->dialPadControlInput(ControlBtn::Empty);
}

void ATMForm::on_receipt_btn_clicked() {
    qDebug() << "get receipt";
    //TODO: Needs implementation
}

void ATMForm::on_card_reader_btn_clicked() {
    qDebug() << "card-reader";
    //TODO: Needs implementation
}

void ATMForm::on_dispenser_btn_clicked() {
    qDebug() << "dispenser";
    //TODO: Needs implementation
}

void ATMForm::on_d0r_btn_clicked() {
    controller_->sideDisplayBtnInput(DisplaySideBtn::R0);
}

void ATMForm::on_d1r_btn_clicked() {
    controller_->sideDisplayBtnInput(DisplaySideBtn::R1);
}

void ATMForm::on_d2r_btn_clicked() {
    controller_->sideDisplayBtnInput(DisplaySideBtn::R2);
}

void ATMForm::on_d3r_btn_clicked() {
    controller_->sideDisplayBtnInput(DisplaySideBtn::R3);
}

void ATMForm::on_d0l_btn_clicked() {
    controller_->sideDisplayBtnInput(DisplaySideBtn::L0);
}

void ATMForm::on_d1l_btn_clicked() {
    controller_->sideDisplayBtnInput(DisplaySideBtn::L1);
}

void ATMForm::on_d2l_btn_clicked() {
    controller_->sideDisplayBtnInput(DisplaySideBtn::L2);
}

void ATMForm::on_d3l_btn_clicked() {
    controller_->sideDisplayBtnInput(DisplaySideBtn::L3);
}

QWebEngineView &ATMForm::getWebView() {
    return *(ui_->display);
}