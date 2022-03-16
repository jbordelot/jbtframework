cmake_minimum_required(VERSION 3.16)

project(jbtStateMachine)

set(
    SOURCES
    code/src/jbtStateMachine.cpp
)

add_library(lib${PROJECT_NAME} ${SOURCES})