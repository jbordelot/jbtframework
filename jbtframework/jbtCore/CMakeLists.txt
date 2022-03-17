cmake_minimum_required(VERSION 3.16)

project(jbtCore)


set(
    SOURCES
    code/src/jbtCore.cpp
)

add_library(${PROJECT_NAME} ${SOURCES})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)