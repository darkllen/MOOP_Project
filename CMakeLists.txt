cmake_minimum_required(VERSION 3.16)
project(MOOP_ATM_Project)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES src/main.cpp src/ATMModel.cpp src/ATMModel.h src/ATMIO.cpp src/ATMIO.h)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS src/ui/)
set(CMAKE_BUILD_TYPE DEBUG)

add_executable(MOOP_ATM_Project ${SOURCE_FILES} resources/resources.qrc)

find_package(Qt5 COMPONENTS Core Widgets Gui Sql WebEngineWidgets REQUIRED)
target_link_libraries(MOOP_ATM_Project Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Sql Qt5::WebEngineWidgets)