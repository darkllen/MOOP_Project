cmake_minimum_required(VERSION 3.16)
project(MOOP_ATM_Project)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES src/main.cpp)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS src/ui/)

add_executable(MOOP_ATM_Project ${SOURCE_FILES})

find_package(Qt5 COMPONENTS Core Widgets Gui Sql REQUIRED)
target_link_libraries(MOOP_ATM_Project Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Sql)