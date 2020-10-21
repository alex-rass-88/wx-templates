cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(wxTemplate)

set(CMAKE_CXX_STANDARD 11)

option(USE_SYSTEM_WX "Use system wxWidgets" ON)

add_subdirectory(third_party)
add_subdirectory(01_hello)
add_subdirectory(02_wxformbuilder)
