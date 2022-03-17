cmake_minimum_required(VERSION 3.16)

project(jbtStateMachine)

set(
    SOURCES
    code/src/jbtStateMachine.cpp
)

add_library(${PROJECT_NAME} ${SOURCES})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)