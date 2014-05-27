
set(BUILD_SHARED_LIBS FALSE)

# SFML maintainers, I am disappoint.
string(REPLACE "-ansi -Wall -Werror" "" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")

add_subdirectory(SFML)
