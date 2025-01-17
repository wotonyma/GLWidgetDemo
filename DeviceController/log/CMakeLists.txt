target_include_directories(${proj_exe} PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(${proj_exe} PUBLIC 
	"log.cpp" 
	"log_cfg_mgr.cpp"
)