cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME delwg)

project(
  ${PROJECT_NAME}
  VERSION 0.0.1
  LANGUAGES CXX)

add_executable(${PROJECT_NAME} src/main.cpp src/html.cpp)

if(UNIT_TEST)
  add_definitions(-DUNIT_TEST)
endif()
