cmake_minimum_required(VERSION 3.16)

project(jbtTimer)

set(
    SOURCES
    code/src/jbtTimer.cpp
)

add_library(lib${PROJECT_NAME} ${SOURCES})