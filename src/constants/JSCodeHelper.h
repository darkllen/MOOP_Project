//
// Created by Lemonderon on 08.11.2020.
//

#ifndef ATM_JSCODEHELPER_H
#define ATM_JSCODEHELPER_H

#include <QtCore/QString>

namespace JS {
    namespace PINEntering {
        namespace PINEnteringScreen {
            QString triesLeftUpdate(const unsigned char triesLeft) {
                return "document.getElementById(\"tries\").innerHTML = 'Tries left: "
                       + QString::number(triesLeft) + "';";
            }

            QString emptyText() {
                return R"~(document.getElementById("text").innerHTML ="";)~";
            }
        }
        QString appendTextWithAsterisk() {
            return "document.getElementById(\"text\").innerHTML += '*';";
        }
    }

    namespace NumEntering {
        QString showEnteredNumber(QString num) {
            return "document.getElementById(\"text\").innerHTML = '" + num + "';";
        }
    }

    namespace General {
        QString setWarning(QString msg) {
            return "document.getElementById(\"warning\").innerHTML = '" + msg + "';";
        }
    }
}


#endif //ATM_JSCODEHELPER_H
