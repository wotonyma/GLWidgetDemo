
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

list(APPEND ${CMAKE_PREFIX_PATH} "$ENV{QTDIR}/lib/cmake")
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Widgets Network RemoteObjects REQUIRED)       #查找Qt6或Qt5，导入Widgets模块
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Network Concurrent RemoteObjects REQUIRED)  #查找Qt具体版本，导入Widgets模块

find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

#生成rep类需要将对应cpp文件列入add_executable(),放入target_source没有用

qt5_generate_repc(rep_src "${CMAKE_SOURCE_DIR}/rep/acs_service.rep" REPLICA)
qt5_generate_repc(rep_src "${CMAKE_SOURCE_DIR}/rep/ymc_service.rep" REPLICA)
qt5_generate_repc(rep_src "${CMAKE_SOURCE_DIR}/rep/plc_service.rep" REPLICA)

set(client "client")
add_executable(${client} "main.cpp" ${rep_src})

target_link_libraries(${client} PUBLIC 
	Qt${QT_VERSION_MAJOR}::Core
	Qt${QT_VERSION_MAJOR}::Widgets
	Qt${QT_VERSION_MAJOR}::RemoteObjects
)

target_link_libraries(${client} PRIVATE
	fmt::fmt-header-only 
	spdlog::spdlog_header_only
)

target_sources(${client} PUBLIC 
	"client_wnd.h"
	"client_wnd.cpp"
	"service_node.h"
	"service_node.cpp"
)

#生成后事件 
#${PROJECT_BINARY_DIR}=顶层cmake二进制生成路径
add_custom_command(
	TARGET ${client} 
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${CMAKE_SOURCE_DIR}/config" "${CMAKE_CURRENT_BINARY_DIR}/config" 
)