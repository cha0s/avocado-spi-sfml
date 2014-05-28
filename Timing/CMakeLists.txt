cmake_minimum_required(VERSION 2.8)

add_library(TimingService-SFML SHARED
	
	implementSpi.cpp
	
	SfmlTimingService.cpp

	SfmlCounter.cpp
	
)

target_link_libraries(TimingService-SFML
	
	sfml-system

)

if(UNIX)

	target_link_libraries(TimingService-SFML
	
		rt

	)
	
endif()

avocado_build_spii_name(TimingService-SFML)
