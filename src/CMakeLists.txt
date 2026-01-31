
# Add an executable target named "MyApp" from the source files list
add_executable(MouseHeartbeat main.cpp)

install(TARGETS MouseHeartbeat 
	CONFIGURATIONS debug
	DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/debug
	COMPONENT Application
)

install(TARGETS MouseHeartbeat 
	CONFIGURATIONS release
	DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/release
	COMPONENT Application
)