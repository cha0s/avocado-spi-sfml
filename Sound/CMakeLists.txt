cmake_minimum_required(VERSION 2.8)

add_library(SoundService-sfml SHARED
	
	implementSpi.cpp
	
	SfmlSoundService.cpp
	
	SfmlSample.cpp
	SfmlMusic.cpp
	
)

target_link_libraries(SoundService-sfml
	
	sfml-audio
	sfml-system
	
	sndfile

)

if(WIN32)

	link_directories(
	
		deps/SFML/extlibs/libs-mingw/x86
	
	)

	target_link_libraries(SoundService-sfml
	
		openal32

	)
	
else()
	
	target_link_libraries(SoundService-sfml
	
		openal

	)
	
endif()

avocado_build_spii_name(SoundService-sfml)
