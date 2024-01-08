cmake_minimum_required(VERSION 3.14)

project(question01_commandLine LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

add_executable(question_01_commandLine
  main.cpp
  filevalidator.h filevalidator.cpp
)
target_link_libraries(question_01_commandLine PRIVATE
    Qt6::Core
    Qt6::Widgets
)

install(TARGETS question_01_commandLine
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
