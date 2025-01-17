
target_include_directories(${proj_exe} PRIVATE 
	"${CMAKE_CURRENT_SOURCE_DIR}"
	"melsecCom"
)

target_sources(${proj_exe} PRIVATE
	"melexception.h"
	"melsecplc.cpp"
	"plcobject.cpp"
	"plcworker.cpp"
	"plccfgmgr.cpp"
)