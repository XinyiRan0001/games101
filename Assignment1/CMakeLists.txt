cmake_minimum_required(VERSION 3.10)
project(Rasterizer1)

set(CMAKE_CXX_STANDARD 17)

include_directories("C:/Users/yesta/Portfolio/games101/Assignment0/external/eigen-5.0.1/eigen-5.0.1")
include_directories("C:/Users/yesta/Portfolio/opencv/build/include")

set(OpenCV_LIBRARIES "C:/Users/yesta/Portfolio/opencv/build/x64/vc16/lib/opencv_world4120d.lib")

file(COPY "C:/Users/yesta/Portfolio/opencv/build/x64/vc16/bin/opencv_world4120d.dll"
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug/)

add_executable(Rasterizer1
    main.cpp
    rasterizer.hpp
    rasterizer.cpp
    Triangle.hpp
    Triangle.cpp
)

target_link_libraries(Rasterizer1 ${OpenCV_LIBRARIES})

