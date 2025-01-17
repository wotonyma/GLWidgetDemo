set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

list(APPEND ${CMAKE_PREFIX_PATH} "$ENV{QtDir_x86}/lib/cmake")
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Widgets Network RemoteObjects REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Network RemoteObjects REQUIRED)

qt5_generate_repc(rep_src "${CMAKE_SOURCE_DIR}/service/laser_service.rep" SOURCE)

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

target_sources(${proj_exe} PRIVATE 
	"laser_cfg_mgr.h" 
	"laser_cfg_mgr.cpp" 
)

#生成后事件
#${PROJECT_BINARAY_DIR}=顶层cmake生成二进制地址
add_custom_command(
	TARGET ${proj_exe} 
	POST_BUILD 
	COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${CMAKE_SOURCE_DIR}/config" "${CMAKE_CURRENT_BINARY_DIR}/config"
)