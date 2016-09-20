CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(DesignPattern)

SET(CODE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/code/)

SET(CMAKE_C_COMPILER /usr/bin/gcc)
SET(CMAKE_CXX_COMPILER /usr/bin/g++)

ADD_DEFINITIONS("-w -Wall -std=c++11 -lpthread -fPIC")

include_directories(public
${CODE_PATH}/src/include
)

aux_source_directory("${CODE_PATH}/src/source" EXE_SOURCE_LIST)
aux_source_directory("${CODE_PATH}/main" EXE_SOURCE_LIST)

link_directories(${EXECUTABLE_OUTPUT_PATH})

SET(TARGET_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)
SET(EXECUTABLE_OUTPUT_PATH ${TARGET_PATH})

message("----------  configure ${PROJECT_NAME} ----------")
add_executable(${PROJECT_NAME} ${EXE_SOURCE_LIST} )
