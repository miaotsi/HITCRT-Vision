cmake_minimum_required(VERSION 3.15)
project(Oct25)

set(CMAKE_CXX_STANDARD 14)

set(OpenCV_DIR /usr/local/opencv4/share/OpenCV)
find_package(OpenCV 4 REQUIRED)
include_directories(SYSTEM ${OpenCV_INCLUDE_DIRS} /usr/local/opencv4/include)

set(SOURCE_FILES main.cpp)

add_executable(Oct25 ${SOURCE_FILES})

target_link_libraries(Oct25 ${OpenCV_LIBS})#链接库