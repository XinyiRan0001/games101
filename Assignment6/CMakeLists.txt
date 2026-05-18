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

add_executable(RayTracing
    main.cpp
    Renderer.cpp
    BVH.cpp
    Scene.cpp
)

target_link_libraries(RayTracing ${OpenCV_LIBRARIES})