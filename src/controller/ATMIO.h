//
// Created by kuchm on 04.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMIO_H
#define MOOP_ATM_PROJECT_ATMIO_H

#include <QtCore/QObject>

class ATMIO : public QObject {
Q_OBJECT
public:
    ATMIO() = default;
    ~ATMIO() override = default;

    enum DialPadBtn {
        D000, D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, DDot
    };

    enum DisplaySideBtn {
        L0, L1, L2, L3, R0, R1, R2, R3
    };

    enum ControlBtn {
        Cancel, Clear, Enter, Empty
    };

    enum DisplayPowerState{
        ON, OFF
    };

    enum DisplayState{

    };

    void dialPadInput(DialPadBtn btn);
    void dialPadControlInput(ControlBtn btn);
    void sideDisplayBtnInput(DisplaySideBtn btn);
    void dispenserInput();
    void cardReaderInput();

private slots:
    void printReceiptOutput();
    void dispenserOutput();
    void cardReaderOutput();
    void displayOutput(DisplayState);
    void displayPower(DisplayPowerState powerState);

signals:
    //TODO: decide the proper logic for communication with JS
    void some_signal_to_emit();
};


#endif //MOOP_ATM_PROJECT_ATMIO_H
