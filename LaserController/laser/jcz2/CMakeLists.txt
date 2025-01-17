
target_include_directories(${proj_exe} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${proj_exe} PRIVATE 
	"jcz2_laser.h"
	"jcz2_laser.cpp"
	"MarkEzdDll.h"
)