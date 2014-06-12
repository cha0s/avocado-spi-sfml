# Avocado SFML SPI implementation

# Building

In order to build this project, you will need:

* git (obviously, gotta get the sources somehow!)
* cmake
* g++ (on Ubuntu, do *sudo apt-get install build-essential*)
* [avocado-cpp-core](https://github.com/cha0s/avocado-cpp-core)

and SFML dependencies:

* pthread
* opengl
* xlib
* xrandr
* freetype
* glew
* jpeg
* sndfile
* openal

First, check out the project:

```
git clone --recursive https://github.com/cha0s/avocado-spi-sfml.git
```

(Note the --recursive flag)

Navigate to the avocado-spi-sfml directory and run these commands:

```
mkdir build
cd build
cmake -DAVOCADO_CPP_CORE_DIRECTORY=/the/path/to/avocado-cpp-core ..
make
```
