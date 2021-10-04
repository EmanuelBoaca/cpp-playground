# set minimum required cmake version 
cmake_minimum_required(VERSION 3.0)


SET(PROJECT_NAME "20_game_of_life_dll")

PROJECT(${PROJECT_NAME})

ADD_DEFINITIONS(-DUNICODE -D_UNICODE)

ADD_DEFINITIONS(-DFELINE_DLL)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules/;${CMAKE_MODULE_PATH}")

SET(CMAKE_CXX_STANDARD 11)

include_directories(include) 

FILE(GLOB HEADER_FILES "include/*.h")

FILE(GLOB SRC_FILES "src/*.cpp")

# specify where to generate the executable file
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

# specify that we are building an executable, and what sources to use 
ADD_LIBRARY(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SRC_FILES})
