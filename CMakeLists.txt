cmake_minimum_required(VERSION 3.12)
project(study-opencv)

set(CMAKE_CXX_STANDARD 14)

#打开Qt的MOC功能和UI文件处理功能
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

#add_executable(study-opencv openCVDemo2/main.cpp openCVDemo2/opencvworker.cpp openCVDemo2/opencvworker.h openCVDemo2/qcvwidget.cpp openCVDemo2/qcvwidget.h openCVDemo2/qcvwidget.ui)

add_executable(study-opencv test/test.cpp)
#add_executable(study-opencv openCVDemo1/main.cpp)

#查找Qt的库
find_package(Qt5Widgets)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(study-opencv ${OpenCV_LIBS}  Qt5::Widgets)



