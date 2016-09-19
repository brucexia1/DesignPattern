CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(DesignPattern)

SET(CODE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/code/)

SET(CMAKE_C_COMPILER /usr/bin/gcc)
SET(CMAKE_CXX_COMPILER /usr/bin/g++)

ADD_DEFINITIONS("-w -Wall -std=c++11 -lpthread -fPIC")

aux_source_directory("${CODE_PATH}/" EXE_SOURCE_LIST)
#aux_source_directory("${CODE_PATH}/source" EXE_SOURCE_LIST)

include_directories(public
${CODE_PATH}/
#${CODE_PATH}/include
)

link_directories(${EXECUTABLE_OUTPUT_PATH})

message("----------  configure ${PROJECT_NAME} ----------")

add_executable(${PROJECT_NAME} ${EXE_SOURCE_LIST} )
#target_link_libraries(DesignPattern libDesignPattern.a)

