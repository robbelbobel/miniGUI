cmake_minimum_required(VERSION 3.23)
project(miniGUI)

# Build Library
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
set(CMAKE_PREFIX_PATH)

add_library(miniGUI src/elements/element.cpp
                    src/elements/imageElement.cpp
                    src/elements/textElement.cpp
                    src/widgets/buttons/buttonWidget.cpp
                    src/widgets/buttons/imageButtonWidget.cpp
                    src/widgets/buttons/textButtonWidget.cpp
                    src/widgets/shapes/rectangleShapeWidget.cpp
                    src/widgets/shapes/shape.cpp
                    src/widgets/imageWidget.cpp
                    src/widgets/textWidget.cpp
                    src/widgets/widget.cpp
                    src/canvas.cpp
                    src/window.cpp)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(miniGUI ${SDL2_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(miniGUI ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Build Examples
add_executable(basic-example examples/basic-example/main.cpp)
target_link_libraries(basic-example miniGUI)

target_compile_definitions(basic-example PRIVATE SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/examples/basic-example/")
