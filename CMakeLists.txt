cmake_minimum_required(VERSION 3.23)
project(miniGUI)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
set(CMAKE_PREFIX_PATH)
set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME}  src/main.cpp
                                src/canvas/canvas.cpp
                                src/widgets/widget.cpp
                                src/widgets/buttons/buttonWidget.cpp
                                src/widgets/buttons/textButtonWidget.cpp
                                src/window/window.cpp)
                                
find_package(SDL2 REQUIRED)

include_directories(${PROJECT_NAME} ${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})