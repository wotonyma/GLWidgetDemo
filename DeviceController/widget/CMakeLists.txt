set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

list(APPEND ${CMAKE_PREFIX_PATH} "$ENV{QTDIR}/lib/cmake")
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Widgets Network RemoteObjects REQUIRED)       #查找Qt6或Qt5，导入Widgets模块
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Network Concurrent RemoteObjects REQUIRED)  #查找Qt具体版本，导入Widgets模块

find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

#生成rep类需要将对应cpp文件列入add_executable(),放入target_source没有用
set(rep_src 
	"service/acs_service.cpp" 
	"service/ymc_service.cpp"
	"service/plc_service.cpp"
	"service/service_worker.cpp"
	"service/service_obj.h"
)
qt5_generate_repc(rep_src "${CMAKE_SOURCE_DIR}/rep/acs_service.rep" SOURCE)
qt5_generate_repc(rep_src "${CMAKE_SOURCE_DIR}/rep/ymc_service.rep" SOURCE)
qt5_generate_repc(rep_src "${CMAKE_SOURCE_DIR}/rep/plc_service.rep" SOURCE)

set(exe_flag)
if (${CMAKE_BUILD_TYPE} STREQUAL "Release")
	set(exe_flag WIN32)
endif()

add_executable(${proj_exe} ${exe_flag} "main.cpp" ${rep_src})

target_link_libraries(${proj_exe} PUBLIC 
	Qt${QT_VERSION_MAJOR}::Core
	Qt${QT_VERSION_MAJOR}::Widgets
	Qt${QT_VERSION_MAJOR}::RemoteObjects
)

target_link_libraries(${proj_exe} PRIVATE
	fmt::fmt-header-only 
	spdlog::spdlog_header_only
)

target_sources(${proj_exe} PUBLIC 
	"dev_widget.cpp"
	"version.rc"
	"init_cfg_mgr.h"
	"init_cfg_mgr.cpp"
	"sub_proc/sub_proc_ctrl.h"
	"sub_proc/sub_proc_ctrl.cpp"
)

#生成后事件 
#${PROJECT_BINARY_DIR}=顶层cmake二进制生成路径
add_custom_command(
	TARGET ${proj_exe} 
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${CMAKE_SOURCE_DIR}/config" "${CMAKE_CURRENT_BINARY_DIR}/config" 
)

