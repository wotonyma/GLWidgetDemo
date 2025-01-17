
set(ACS_LIB_DIR "C:/Program Files (x86)/ACS Motion Control/SPiiPlus 6.60/ACSC/C_CPP")

target_include_directories(${proj_exe} PUBLIC 
	"${CMAKE_CURRENT_SOURCE_DIR}"
	"${ACS_LIB_DIR}" 
)

target_sources(${proj_exe} PUBLIC 
	"ACSObject.cpp" 
	"ACSWorker.cpp"
	"ACSController.cpp"
)

target_link_libraries(${proj_exe} PUBLIC 
	"${ACS_LIB_DIR}/ACSCL_x64.LIB"
)