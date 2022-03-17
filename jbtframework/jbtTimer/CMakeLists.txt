cmake_minimum_required(VERSION 3.16)

project(jbtTimer)

set(
    SOURCES
    code/src/jbtTimer.cpp
    code/src/jbtScopedTimer.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

target_include_directories(${PROJECT_NAME} PUBLIC code/inc)