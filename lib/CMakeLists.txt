
#정적 라이브러리 생성
add_library(mylib 
	STATIC
	mylib.cpp
)

#헤더 파일 경로 설정
target_include_directories(mylib 
	PUBLIC 
		${CMAKE_SOURCE_DIR}/lib
		${CMAKE_SOURCE_DIR}/include
		${Vulkan_INCLUDE_DIR}
)

#외부 라이브러리 링크
target_link_libraries(mylib 
	PUBLIC 
		EnTT::EnTT 
		raylib
		Vulkan::Vulkan
)

# PCH 설정
target_precompile_headers(mylib 
	PUBLIC	
		${CMAKE_SOURCE_DIR}/include/pch.h
)
