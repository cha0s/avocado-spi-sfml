cmake_minimum_required(VERSION 2.8)

add_library(GraphicsService-sfml SHARED
	
	implementSpi.cpp
	
	SfmlGraphicsService.cpp
	
	SfmlCanvas.cpp
	SfmlFont.cpp
	SfmlImage.cpp
	SfmlSprite.cpp
	SfmlWindow.cpp
	
)

target_link_libraries(GraphicsService-sfml
	
	sfml-graphics
	sfml-window
	sfml-system
	
	jpeg
	freetype

)

if(WIN32)

	link_directories(
	
		deps/SFML/extlibs/libs-mingw/x86
	
	)

	target_link_libraries(GraphicsService-sfml
	
		glew

	)
	
else()
	
	target_link_libraries(GraphicsService-sfml
	
		GL Xrandr GLEW rt

	)
	
endif()

avocado_build_spii_name(GraphicsService-sfml)
