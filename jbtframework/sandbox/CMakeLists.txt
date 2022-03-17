cmake_minimum_required(VERSION 3.16)

project(sandbox)

set(
    SOURCES
    code/src/main.cpp
    code/src/TimerManager.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

target_include_directories(${PROJECT_NAME} PUBLIC code/inc)
target_include_directories(${PROJECT_NAME} PUBLIC ../jbtTimer/code/inc)

target_link_libraries(${PROJECT_NAME} jbtTimer)