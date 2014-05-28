cmake_minimum_required(VERSION 2.8)

add_library(CoreService-sfml SHARED
	
	implementSpi.cpp
	
	SfmlCoreService.cpp
	
)

avocado_build_spii_name(CoreService-sfml)
