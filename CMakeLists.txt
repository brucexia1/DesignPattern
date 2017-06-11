CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(DesignPattern)

SET(PRJ_PATH ${CMAKE_CURRENT_SOURCE_DIR}/)

SET(CMAKE_C_COMPILER /usr/bin/gcc)
SET(CMAKE_CXX_COMPILER /usr/bin/g++)

ADD_DEFINITIONS("-w -Wall -std=c++11 -lpthread -fPIC")

SET(LIB_PATH ${PRJ_PATH}/3rdlib/gtest/buildUnix)

include_directories(public
${PRJ_PATH}/src/algorithm
${PRJ_PATH}/src/designpattern
${PRJ_PATH}/src/other
${PRJ_PATH}/test
)

aux_source_directory("${PRJ_PATH}/src/algorithm" EXE_SOURCE_LIST)
aux_source_directory("${PRJ_PATH}/src/designpattern" EXE_SOURCE_LIST)
aux_source_directory("${PRJ_PATH}/src/other" EXE_SOURCE_LIST)
aux_source_directory("${PRJ_PATH}/test" EXE_SOURCE_LIST)

link_directories(${EXECUTABLE_OUTPUT_PATH})

SET(TARGET_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)
SET(EXECUTABLE_OUTPUT_PATH ${TARGET_PATH})

message("----------  configure ${PROJECT_NAME} ----------")
add_executable(${PROJECT_NAME} ${EXE_SOURCE_LIST} )
target_link_libraries(${PROJECT_NAME} gtest gmock)
