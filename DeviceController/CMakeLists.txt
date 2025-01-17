cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

project(DeviceController LANGUAGES CXX)

#IF(MSVC)
#	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -openmp:experimental")
#ENDIF()

set(proj_exe "DevCtlComm")

add_subdirectory("widget")

add_subdirectory("log")

add_subdirectory("acs")

add_subdirectory("ymc")

add_subdirectory("plc")

###############################
add_subdirectory("client_test")





