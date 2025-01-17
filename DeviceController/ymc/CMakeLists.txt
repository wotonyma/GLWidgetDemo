#°²´¨°å¿¨Mp720ver7 sdk
set(YMCAPI_DIR "C:/Yetools/PCAPI")

target_include_directories(${proj_exe} PRIVATE 
	"${YMCAPI_DIR}/Include"
	"${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(${proj_exe} PRIVATE "${YMCAPI_DIR}/Lib/ymcPCAPI_x64.lib")


target_sources(${proj_exe} PRIVATE 
	"YmcCommon.h"
	"YmcObject.cpp"
	"YmcWorker.cpp"
	"YmcController.cpp"
)
