cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

project(GLGraphicsDemo CXX)

add_executable(${PROJECT_NAME} main.cpp)

#qt
set(CMAKE_PREFIX_PATH  "$ENV{QTDIR}/lib/cmake")
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)       #查找Qt6或Qt5，导入Widgets模块
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)  #查找Qt具体版本，导入Widgets模块
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

#qrc
target_sources(${PROJECT_NAME} PRIVATE res.qrc)

#glwidget
#target_sources(${PROJECT_NAME} PRIVATE GLWidget.cpp GLGraphicsView.cpp ImageGraphicsItem.cpp)
target_sources(${PROJECT_NAME} PRIVATE GLWidget.cpp GLGraphicsView.cpp OpenGLPixmapItem.cpp OpenGlWidgetItem.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE opengl32)