# Build Status #
[![Build Status](https://travis-ci.org/Gunn3r1995/glex.svg?branch=master)](https://travis-ci.org/Gunn3r1995/glex)

# Prerequisites #

* GNU Autotools
* OpenGL 3.0
* C++11 compiler (tested with GCC 4.8.3+)
* [Boost](http://www.boost.org/)
* [GLEW](http://glew.sourceforge.net/)
* [SDL2](https://www.libsdl.org/)
* [GLM](http://glm.g-truc.net/)

On Fedora 20 or later you can install these using a single command (as root):

``` bash
$ yum install boost-* glew-devel SDL2_* glm-devel
```

# Building #

After cloneing the source code or extracting a distributed archive, change to the
directory where the source code is:

``` bash
$ autoreconf -i
$ ./configure
$ make
```
Alternatively, if you'd like to build the project in debug mode use:
``` bash
$ make CXXFLAGS=-DDEBUG
```
# Running #

The build process should create a binary that can be executed as follows:

``` bash
$ ./src/shaderexample
```

See

``` bash
$ ./src/shaderexample --help
```

for usage instructions.

# Python Bind Building #

``` bash
$ cd src/
$ export PYTHONPATH=`pwd`/.libs/ 
$ cd .. &&make
```

# Python Running #

``` bash
$ python src/PythonBind.py
```

#CPP CHECK#

``` bash
 $ cppcheck ./src --enable=all --check-config 2> CPPCheck.txt
 $ cppcheck ./src --enable=all --check-config >> CPPCHECKGlex.txt 
```


