add_executable(game
	main.cpp
)

target_include_directories(game 
	PRIVATE 
		${CMAKE_SOURCE_DIR}/include
		${Vulkan_INCLUDE_DIR}
)

target_precompile_headers(game 
	PRIVATE	
		${CMAKE_SOURCE_DIR}/include/pch.h
)

target_compile_definitions(game
	PRIVATE
		VK_USE_PLATFORM_WIN32_KHR
)

target_link_libraries(game 
	PRIVATE	
		mylib
		EnTT::EnTT
		raylib
		Vulkan::Vulkan
)

