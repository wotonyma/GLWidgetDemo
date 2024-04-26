

SET (cpp_src "qml_main.cpp")

SET (qml_src "qml.qrc")

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(${PROJECT_NAME} PRIVATE ${cpp_src} ${qml_src})