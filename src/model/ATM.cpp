//
// Created by kuchm on 04.10.2020.
//

#include "ATM.h"

ATM::ATM() : io_(new ATMIO) {

}

ATM::~ATM() {
    delete io_;
}


ATMIO &ATM::getIO() {
    return *io_;
}
