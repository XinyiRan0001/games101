cmake_minimum_required(VERSION 3.10)

project(BezierCurve)

set(CMAKE_CXX_STANDARD 17)

include_directories("C:/Users/yesta/Portfolio/opencv/build/include")

set(OpenCV_LIBRARIES
    "C:/Users/yesta/Portfolio/opencv/build/x64/vc16/lib/opencv_world4120d.lib"
)

file(COPY
    "C:/Users/yesta/Portfolio/opencv/build/x64/vc16/bin/opencv_world4120d.dll"
    DESTINATION
    ${CMAKE_CURRENT_BINARY_DIR}/Debug/
)

add_executable(BezierCurve main.cpp)

target_link_libraries(BezierCurve ${OpenCV_LIBRARIES})
