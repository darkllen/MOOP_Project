cmake_minimum_required(VERSION 3.16)
project(MOOP_ATM_Project)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        src/main.cpp
        src/ui/ATMForm.cpp
        src/ui/ATMForm.h
        src/controllers/AccountActions.h
        src/controllers/ATMController.h
        src/controllers/ATMQtUiController.cpp
        src/controllers/ATMQtUiController.h
        src/controllers/CardPinCheck.h
        src/controllers/Maintenance.h
        src/exceptions/ATMException.h
        src/exceptions/DBException.h
        src/exceptions/HardwareException.h
        src/exceptions/IOException.h
        src/exceptions/TransactionException.h
        src/mediators/ATMIO.cpp
        src/mediators/ATMIO.h
        src/models/Account.h
        src/models/AccountManaging.h
        src/models/ATM.cpp
        src/models/ATM.h
        src/models/ATMEvent.h
        src/models/ATMInfo.h
        src/models/Bank.h
        src/models/Cash.h
        src/models/CheckingAccount.h
        src/models/Customer.h
        src/models/DebitCard.h
        src/models/OneTimeTransfer.h
        src/models/RegularTransfer.h
        src/models/SavingAccount.h
        src/models/SessionManager.h
        src/models/Transaction.h
        src/models/TransactionManager.h
        src/models/Dispenser.h src/models/CardReader.h src/models/Hardware.h src/constants/ATM_Types.h src/controllers/InputValidation.h src/tests/Tester.h)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS src/ui/)
set(CMAKE_BUILD_TYPE DEBUG)

add_executable(MOOP_ATM_Project ${SOURCE_FILES} resources/resources.qrc)

find_package(Qt5 COMPONENTS Core Widgets Gui Sql WebEngineWidgets REQUIRED)
target_link_libraries(MOOP_ATM_Project Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Sql Qt5::WebEngineWidgets)