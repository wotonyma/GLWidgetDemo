
target_include_directories(${proj_exe} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${proj_exe} PRIVATE 
	"laser.h"
	"jcz2/bmp_ent.h"
	"laser_ctrl.h"
	"laser_ctrl.cpp"
)

add_subdirectory("jcz2")