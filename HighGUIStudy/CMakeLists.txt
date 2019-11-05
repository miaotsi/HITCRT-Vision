cmake_minimum_required(VERSION 3.15)
project(HighGUIStudy)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

set(SOURCE_FILES main.cpp)

add_executable(HighGUIStudy ${SOURCE_FILES})

target_link_libraries(HighGUIStudy ${OpenCV_LIBS})#链接库