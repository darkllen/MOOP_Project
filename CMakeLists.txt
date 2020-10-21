cmake_minimum_required(VERSION 3.16)
project(MOOP_ATM_Project)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        src/main.cpp
        src/ui/ATMForm.cpp
        src/ui/ATMForm.h
        src/controllers/AccountActions.h
        src/controllers/ATMController.h
        src/controllers/ui/ATMQtUiController.cpp
        src/controllers/ui/ATMQtUiController.h
        src/controllers/PinVerificationService.h
        src/controllers/Maintenance.h
        src/exceptions/ATMException.h
        src/mediators/ATMIO.cpp
        src/mediators/ATMIO.h
        src/models/accounts/Account.h
        src/models/transactions/AccountManaging.h
        src/models/ATM.cpp
        src/models/ATM.h
        src/models/ATMEvent.h
        src/models/ATMInfo.h
        src/models/Bank.h
        src/models/transactions/CashTransaction.h
        src/models/transactions/CheckingAccount.h
        src/models/Customer.h
        src/models/DebitCard.h
        src/models/transactions/OneTimeTransfer.h
        src/models/transactions/RegularTransfer.h
        src/models/accounts/SavingAccount.h
        src/models/SessionManager.h
        src/models/transactions/Transaction.h
        src/models/TransactionManager.h
        src/models/atm_hardware/Dispenser.h
        src/models/atm_hardware/CardReader.h
        src/models/atm_hardware/Hardware.h
        src/constants/ATMTypes.h
        src/helpers/InputValidation.h
        src/tests/Tester.h
        src/controllers/ui/ATMQtDisplayController.h
        src/controllers/Maintenance.cpp
        src/models/atm_hardware/CardReader.cpp
        src/controllers/PinVerificationService.cpp
        src/controllers/ui/ATMQtUiController.cpp
        src/controllers/ui/ATMQtDisplayController.cpp
        src/controllers/AccountActions.cpp
        src/constants/ATMLimits.h
        src/models/atm_hardware/Dispenser.cpp
        src/models/accounts/Account.cpp
        src/models/Bank.cpp
        src/models/SessionManager.cpp
        src/models/TransactionManager.cpp)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS src/ui/)
set(CMAKE_BUILD_TYPE DEBUG)

add_executable(MOOP_ATM_Project ${SOURCE_FILES} resources/resources.qrc)

find_package(Qt5 COMPONENTS Core Widgets Gui Sql WebEngineWidgets REQUIRED)
target_link_libraries(MOOP_ATM_Project Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Sql Qt5::WebEngineWidgets)