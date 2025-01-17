cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_compile_definitions(UNICODE _UNICODE)
#add_definitions("-DUNICODE" "-D_UNICODE")

project(Laser LANGUAGES CXX)

#IF(MSVC)
#	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -openmp:experimental")
#ENDIF()

set(proj_exe "LaserCtrl")

add_subdirectory("widget")

add_subdirectory("laser")

add_subdirectory("service")




