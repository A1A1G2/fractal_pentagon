cmake_minimum_required(VERSION 3.0.0)
set(PROJECT_NAME fractalPentagon)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCES main.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)
find_package(Curses REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})	
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics ${CURSES_LIBRARIES})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
if (UNIX)
    target_link_libraries(${PROJECT_NAME} pthread)
endif (UNIX)

