cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

project(qmlTest LANGUAGES CXX)

add_executable(${PROJECT_NAME})

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt-header-only)

#qt
list(APPEND CMAKE_PREFIX_PATH "$ENV{QTDIR}/lib/cmake") #注意要用大写的APPEND
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)       #查找Qt6或Qt5，导入Widgets模块
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)  #查找Qt具体版本，导入Widgets模块
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core
												Qt${QT_VERSION_MAJOR}::Quick
)

#包含子项目
add_subdirectory("qml")
