cmake_minimum_required(VERSION 3.12)
project(study-opencv)

set(CMAKE_CXX_STANDARD 14)

add_executable(study-opencv main.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(study-opencv ${OpenCV_LIBS})