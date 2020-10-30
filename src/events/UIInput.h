//
// Created by Lemonderon on 26.10.2020.
//

#ifndef ATM_UIINPUT_H
#define ATM_UIINPUT_H

namespace UIButtonsInput {
    enum DialPad {
        D000, D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, DDot
    };
    enum DisplaySideButton {
        L0, L1, L2, L3, R0, R1, R2, R3
    };
    enum ControlPad {
        Cancel, Clear, Enter, Empty
    };
}

enum ATMPowerState {
    On, Off
};
#endif //ATM_UIINPUT_H
