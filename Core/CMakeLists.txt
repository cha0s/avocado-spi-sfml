cmake_minimum_required(VERSION 2.8)

add_library(CoreService-SFML SHARED
	
	SfmlCoreService.cpp
	
)

avocado_build_spii_name(CoreService-SFML)
