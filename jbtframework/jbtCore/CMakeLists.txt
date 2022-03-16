cmake_minimum_required(VERSION 3.16)

project(jbtCore)


set(
    SOURCES
    code/src/jbtCore.cpp
)

add_library(lib${PROJECT_NAME} ${SOURCES})