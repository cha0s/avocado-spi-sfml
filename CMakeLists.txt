cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED AVOCADO_CPP_CORE_DIRECTORY)
	message(STATUS "Avocado CPP core will use the ./core directory by default...")
	set(AVOCADO_CPP_CORE_DIRECTORY ./core)
endif()

if(NOT EXISTS ${AVOCADO_CPP_CORE_DIRECTORY})
	message(FATAL_ERROR "Avocado CPP core is not available!")
endif()

include(${AVOCADO_CPP_CORE_DIRECTORY}/CMakeLists-core.txt)

project(SPII-SFML)

include_directories(deps/SFML/include)

cmake_policy(SET CMP0015 NEW)
link_directories(

	${CMAKE_CURRENT_BINARY_DIR}/deps
	${CMAKE_CURRENT_BINARY_DIR}/deps/SFML/lib/

)

if(NOT DEFINED LIBRARY_OUTPUT_PATH)
	set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")
endif()

add_subdirectory(deps)
add_subdirectory(Core)
add_subdirectory(Graphics)
add_subdirectory(Sound)
add_subdirectory(Timing)
