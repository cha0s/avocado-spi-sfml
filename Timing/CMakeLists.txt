cmake_minimum_required(VERSION 2.8)

add_library(TimingService-sfml SHARED
	
	implementSpi.cpp
	
	SfmlTimingService.cpp
	
)

target_link_libraries(TimingService-sfml
	
	sfml-system

)

if(UNIX)

	target_link_libraries(TimingService-sfml
	
		rt

	)
	
endif()

avocado_build_spii_name(TimingService-sfml)
