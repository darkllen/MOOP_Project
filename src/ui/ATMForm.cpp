//
// Created by Lemonderon on 02.10.2020.
//

#include <QWebChannel>

#include "ATMForm.h"
#include "ui_mainwindow.h"

ATMForm::ATMForm(QMainWindow& mw, ATMIO& atm_io) : QWidget(), ui_(new Ui::MainWindowForm), atm_io_(&atm_io) {
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
    qDebug() << "000-keypad";
    atm_->getIO().dialPadInput(ATMIO::DialPadBtn::D000);
}

void ATMForm::on_n0_keypad_btn_clicked() {
    qDebug() << "0-keypad";
    atm_->getIO().dialPadInput(ATMIO::DialPadBtn::D0);
}

void ATMForm::on_n1_keypad_btn_clicked() {
    qDebug() << "1-keypad";
    atm_->getIO().dialPadInput(ATMIO::DialPadBtn::D1);
}

void ATMForm::on_n2_keypad_btn_clicked() {
    qDebug() << "2-keypad";
    atm_->getIO().dialPadInput(ATMIO::DialPadBtn::D2);
}

void ATMForm::on_n3_keypad_btn_clicked() {
    qDebug() << "3-keypad";
    atm_->getIO().dialPadInput(ATMIO::DialPadBtn::D3);
}

void ATMForm::on_n4_keypad_btn_clicked() {
    qDebug() << "4-keypad";
    atm_->getIO().dialPadInput(ATMIO::DialPadBtn::D4);
}

void ATMForm::on_n5_keypad_btn_clicked() {
    qDebug() << "5-keypad";
    atm_->getIO().dialPadInput(ATMIO::DialPadBtn::D5);
}

void ATMForm::on_n6_keypad_btn_clicked() {
    qDebug() << "6-keypad";
    atm_->getIO().dialPadInput(ATMIO::DialPadBtn::D6);
}

void ATMForm::on_n7_keypad_btn_clicked() {
    qDebug() << "7-keypad";
    atm_->getIO().dialPadInput(ATMIO::DialPadBtn::D7);
}

void ATMForm::on_n8_keypad_btn_clicked() {
    qDebug() << "8-keypad";
    atm_->getIO().dialPadInput(ATMIO::DialPadBtn::D8);
}

void ATMForm::on_n9_keypad_btn_clicked() {
    qDebug() << "9-keypad";
    atm_->getIO().dialPadInput(ATMIO::DialPadBtn::D9);
}

void ATMForm::on_dot_keypad_btn_clicked() {
    qDebug() << ".-keypad";
    atm_->getIO().dialPadInput(ATMIO::DialPadBtn::DDot);
}

void ATMForm::on_cancel_keypad_btn_clicked() {
    qDebug() << "cancel-keypad";
    atm_->getIO().dialPadControlInput(ATMIO::ControlBtn::Cancel);
}

void ATMForm::on_clear_keypad_btn_clicked() {
    qDebug() << "clear-keypad";
    atm_->getIO().dialPadControlInput(ATMIO::ControlBtn::Clear);
}

void ATMForm::on_enter_keypad_btn_clicked() {
    qDebug() << "enter-keypad";
    atm_->getIO().dialPadControlInput(ATMIO::ControlBtn::Enter);
}

void ATMForm::on_empty_keypad_btn_clicked() {
    qDebug() << "empty-keypad";
    atm_->getIO().dialPadControlInput(ATMIO::ControlBtn::Empty);
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
    qDebug() << "d0r";
    atm_->getIO().sideDisplayBtnInput(ATMIO::DisplaySideBtn::R0);
}

void ATMForm::on_d1r_btn_clicked() {
    qDebug() << "d1r";
    atm_->getIO().sideDisplayBtnInput(ATMIO::DisplaySideBtn::R1);
}

void ATMForm::on_d2r_btn_clicked() {
    qDebug() << "d2r";
    atm_->getIO().sideDisplayBtnInput(ATMIO::DisplaySideBtn::R2);
}

void ATMForm::on_d3r_btn_clicked() {
    qDebug() << "d3r";
    atm_->getIO().sideDisplayBtnInput(ATMIO::DisplaySideBtn::R3);
}

void ATMForm::on_d0l_btn_clicked() {
    qDebug() << "d0l";
    atm_->getIO().sideDisplayBtnInput(ATMIO::DisplaySideBtn::L0);
}

void ATMForm::on_d1l_btn_clicked() {
    qDebug() << "d1l";
    atm_->getIO().sideDisplayBtnInput(ATMIO::DisplaySideBtn::L1);
}

void ATMForm::on_d2l_btn_clicked() {
    qDebug() << "d2l";
    atm_->getIO().sideDisplayBtnInput(ATMIO::DisplaySideBtn::L2);
}

void ATMForm::on_d3l_btn_clicked() {
    qDebug() << "d3l";
    atm_->getIO().sideDisplayBtnInput(ATMIO::DisplaySideBtn::L3);
}
QWebEngineView &ATMForm::getWebView() {
    return *(ui_->display);
}
QWebEnginePage &ATMForm::getWebPage() {
    return *(ui_->display->page());
}
