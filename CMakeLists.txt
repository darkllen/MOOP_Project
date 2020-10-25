cmake_minimum_required(VERSION 3.16)
project(ATM)

set(CMAKE_CXX_STANDARD 17)


# auto-compile options
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS src/ui/)


set(SOURCE_FILES
        resources/resources.qrc
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
        src/models/accounts/CheckingAccount.h
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
        src/models/TransactionManager.cpp
        src/helpers/InputValidation.cpp)

# changing output folder for .exe and .dll
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# path for used libs:
SET(QT_BIN_PATH "" CACHE PATH "Path to Qt bin dir")
SET(MYSQL_CPP_DEBUG_PATH "" CACHE PATH "Path to MySQL_Connector_C++ Debug dir")
SET(MYSQL_CPP_RELEASE_PATH "" CACHE PATH "Path to MySQL_Connector_C++ Release dir")


# set prefix for Qt app
set(CMAKE_PREFIX_PATH ${QT_BIN_PATH})


# include MySQL_Connector_C++
if (CMAKE_BUILD_TYPE MATCHES Debug)
    include_directories(${PROJECT_NAME} PUBLIC ${MYSQL_CPP_DEBUG_PATH}/include)
    find_library(MYSQL_CONN_LIB mysqlcppconn8 HINTS ${MYSQL_CPP_DEBUG_PATH}/lib64/vs14/debug)
else ()
    include_directories(${PROJECT_NAME} PUBLIC ${MYSQL_CPP_RELEASE_PATH}/include)
    find_library(MYSQL_CONN_LIB mysqlcppconn8 HINTS ${MYSQL_CPP_RELEASE_PATH}/lib64/vs14)
endif ()


# bundle executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
find_package(Qt5 COMPONENTS Widgets WebEngineWidgets REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::WebEngineWidgets ${MYSQL_CONN_LIB})


# bundle created executable with required qt dlls and libs
find_program(WINDEPLOYQT_EXECUTABLE NAME windeployqt HINTS ${QT_BIN_PATH})
if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${WINDEPLOYQT_EXECUTABLE} --debug --no-translations $<TARGET_FILE:${PROJECT_NAME}>)
else ()
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${WINDEPLOYQT_EXECUTABLE} --release --no-translations $<TARGET_FILE:${PROJECT_NAME}>)
endif ()

# bundle created executable with required MySQL_Connector_C++ dlls
if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${MYSQL_CPP_DEBUG_PATH}/lib64/debug/mysqlcppconn8-2-vs14.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${MYSQL_CPP_DEBUG_PATH}/lib64/libssl-1_1-x64.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${MYSQL_CPP_DEBUG_PATH}/lib64/libcrypto-1_1-x64.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)
else ()
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${MYSQL_CPP_RELEASE_PATH}/lib64/mysqlcppconn8-2-vs14.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${MYSQL_CPP_RELEASE_PATH}/lib64/libssl-1_1-x64.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${MYSQL_CPP_RELEASE_PATH}/lib64/libcrypto-1_1-x64.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif ()