//
// Created by Lemonderon on 08.11.2020.
//

#ifndef ATM_CONVERTERS_H
#define ATM_CONVERTERS_H

#include <QtCore/QString>
#include "../events/UIInput.h"

QString dialPadBtnToString(const UIButtonsInput::DialPad btn) {
    switch (btn) {
        case UIButtonsInput::D000:
            return "0000";
        case UIButtonsInput::D0:
            return "0";
        case UIButtonsInput::D1:
            return "1";
        case UIButtonsInput::D2:
            return "2";
        case UIButtonsInput::D3:
            return "3";
        case UIButtonsInput::D4:
            return "4";
        case UIButtonsInput::D5:
            return "5";
        case UIButtonsInput::D6:
            return "6";
        case UIButtonsInput::D7:
            return "7";
        case UIButtonsInput::D8:
            return "8";
        case UIButtonsInput::D9:
            return "9";
        case UIButtonsInput::DDot:
            return ".";
    }
}

#endif //ATM_CONVERTERS_H
