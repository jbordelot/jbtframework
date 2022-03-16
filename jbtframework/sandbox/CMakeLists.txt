cmake_minimum_required(VERSION 3.16)

project(sandbox)

set(
    SOURCES
    code/src/main.cpp
)

add_executable(${PROJECT_NAME}.bin ${SOURCES})