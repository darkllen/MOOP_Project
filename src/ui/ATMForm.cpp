//
// Created by Lemonderon on 02.10.2020.
//

#include <QWebChannel>

#include "ATMForm.h"
#include "ui_mainwindow.h"

ATMForm::ATMForm(QMainWindow &mw, ATMIO &atm_io) : QWidget(), ui(new Ui::MainWindowForm), atm_io_(&atm_io) {
    ui->setupUi(&mw);
    configureSignalAndSlots();
    setMainWindowBackground(mw);
}

ATMForm::~ATMForm() {
    delete ui;
}

void ATMForm::configureSignalAndSlots() {
    connect(ui->n000_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n000_keypad_btn_clicked);
    connect(ui->n0_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n0_keypad_btn_clicked);
    connect(ui->n1_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n1_keypad_btn_clicked);
    connect(ui->n2_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n2_keypad_btn_clicked);
    connect(ui->n3_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n3_keypad_btn_clicked);
    connect(ui->n4_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n4_keypad_btn_clicked);
    connect(ui->n5_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n5_keypad_btn_clicked);
    connect(ui->n6_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n6_keypad_btn_clicked);
    connect(ui->n7_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n7_keypad_btn_clicked);
    connect(ui->n8_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n8_keypad_btn_clicked);
    connect(ui->n9_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_n9_keypad_btn_clicked);
    connect(ui->dot_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_dot_keypad_btn_clicked);
    connect(ui->cancel_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_cancel_keypad_btn_clicked);
    connect(ui->clear_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_clear_keypad_btn_clicked);
    connect(ui->enter_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_enter_keypad_btn_clicked);
    connect(ui->empty_keypad_btn, &QPushButton::clicked, this, &ATMForm::on_empty_keypad_btn_clicked);

    connect(ui->receipt_btn, &QPushButton::clicked, this, &ATMForm::on_receipt_btn_clicked);
    connect(ui->card_reader_btn, &QPushButton::clicked, this, &ATMForm::on_card_reader_btn_clicked);
    connect(ui->dispenser_btn, &QPushButton::clicked, this, &ATMForm::on_dispenser_btn_clicked);

    connect(ui->d0r_btn, &QPushButton::clicked, this, &ATMForm::on_d0r_btn_clicked);
    connect(ui->d1r_btn, &QPushButton::clicked, this, &ATMForm::on_d1r_btn_clicked);
    connect(ui->d2r_btn, &QPushButton::clicked, this, &ATMForm::on_d2r_btn_clicked);
    connect(ui->d3r_btn, &QPushButton::clicked, this, &ATMForm::on_d3r_btn_clicked);

    connect(ui->d0l_btn, &QPushButton::clicked, this, &ATMForm::on_d0l_btn_clicked);
    connect(ui->d1l_btn, &QPushButton::clicked, this, &ATMForm::on_d1l_btn_clicked);
    connect(ui->d2l_btn, &QPushButton::clicked, this, &ATMForm::on_d2l_btn_clicked);
    connect(ui->d3l_btn, &QPushButton::clicked, this, &ATMForm::on_d3l_btn_clicked);
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
    atm_io_->dialPadInput(ATMIO::DialPadBtn::D000);
}

void ATMForm::on_n0_keypad_btn_clicked() {
    qDebug() << "0-keypad";
    atm_io_->dialPadInput(ATMIO::DialPadBtn::D0);
}

void ATMForm::on_n1_keypad_btn_clicked() {
    qDebug() << "1-keypad";
    atm_io_->dialPadInput(ATMIO::DialPadBtn::D1);
}

void ATMForm::on_n2_keypad_btn_clicked() {
    qDebug() << "2-keypad";
    atm_io_->dialPadInput(ATMIO::DialPadBtn::D2);
}

void ATMForm::on_n3_keypad_btn_clicked() {
    qDebug() << "3-keypad";
    atm_io_->dialPadInput(ATMIO::DialPadBtn::D3);
}

void ATMForm::on_n4_keypad_btn_clicked() {
    qDebug() << "4-keypad";
    atm_io_->dialPadInput(ATMIO::DialPadBtn::D4);
}

void ATMForm::on_n5_keypad_btn_clicked() {
    qDebug() << "5-keypad";
    atm_io_->dialPadInput(ATMIO::DialPadBtn::D5);
}

void ATMForm::on_n6_keypad_btn_clicked() {
    qDebug() << "6-keypad";
    atm_io_->dialPadInput(ATMIO::DialPadBtn::D6);
}

void ATMForm::on_n7_keypad_btn_clicked() {
    qDebug() << "7-keypad";
    atm_io_->dialPadInput(ATMIO::DialPadBtn::D7);
}

void ATMForm::on_n8_keypad_btn_clicked() {
    qDebug() << "8-keypad";
    atm_io_->dialPadInput(ATMIO::DialPadBtn::D8);
}

void ATMForm::on_n9_keypad_btn_clicked() {
    qDebug() << "9-keypad";
    atm_io_->dialPadInput(ATMIO::DialPadBtn::D9);
}

void ATMForm::on_dot_keypad_btn_clicked() {
    qDebug() << ".-keypad";
    atm_io_->dialPadInput(ATMIO::DialPadBtn::DDot);
}

void ATMForm::on_cancel_keypad_btn_clicked() {
    qDebug() << "cancel-keypad";
    atm_io_->dialPadControlInput(ATMIO::ControlBtn::Cancel);
}

void ATMForm::on_clear_keypad_btn_clicked() {
    qDebug() << "clear-keypad";
    atm_io_->dialPadControlInput(ATMIO::ControlBtn::Clear);
}

void ATMForm::on_enter_keypad_btn_clicked() {
    qDebug() << "enter-keypad";
    atm_io_->dialPadControlInput(ATMIO::ControlBtn::Enter);
}

void ATMForm::on_empty_keypad_btn_clicked() {
    qDebug() << "empty-keypad";
    atm_io_->dialPadControlInput(ATMIO::ControlBtn::Empty);
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
    atm_io_->sideDisplayBtnInput(ATMIO::DisplaySideBtn::R0);
}

void ATMForm::on_d1r_btn_clicked() {
    qDebug() << "d1r";
    atm_io_->sideDisplayBtnInput(ATMIO::DisplaySideBtn::R1);
}

void ATMForm::on_d2r_btn_clicked() {
    qDebug() << "d2r";
    atm_io_->sideDisplayBtnInput(ATMIO::DisplaySideBtn::R2);
}

void ATMForm::on_d3r_btn_clicked() {
    qDebug() << "d3r";
    atm_io_->sideDisplayBtnInput(ATMIO::DisplaySideBtn::R3);
}

void ATMForm::on_d0l_btn_clicked() {
    qDebug() << "d0l";
    atm_io_->sideDisplayBtnInput(ATMIO::DisplaySideBtn::L0);
}

void ATMForm::on_d1l_btn_clicked() {
    qDebug() << "d1l";
    atm_io_->sideDisplayBtnInput(ATMIO::DisplaySideBtn::L1);
}

void ATMForm::on_d2l_btn_clicked() {
    qDebug() << "d2l";
    atm_io_->sideDisplayBtnInput(ATMIO::DisplaySideBtn::L2);
}

void ATMForm::on_d3l_btn_clicked() {
    qDebug() << "d3l";
    atm_io_->sideDisplayBtnInput(ATMIO::DisplaySideBtn::L3);
}

QWebEngineView &ATMForm::getWebView() {
    return *(ui->display);
}

QWebEnginePage &ATMForm::getWebPage() {
    return *(ui->display->page());
}
