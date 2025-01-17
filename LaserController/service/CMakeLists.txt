
target_include_directories(${proj_exe} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${proj_exe} PRIVATE 
	"laser_service.h"
	"laser_service.cpp"
	"service_ctrl.h" 
	"service_ctrl.cpp" 
)