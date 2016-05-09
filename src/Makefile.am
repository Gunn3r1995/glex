EXTRA_DIST = GameWorld.h GameAssetManager.h GameAsset.h CubeAsset.h DiamondAsset.h GroundAsset.h LeavesAsset.h PyramidAsset.h GrassAsset.h BoundingBox.h Camera.h GameLoop.h

bin_PROGRAMS = shaderexample
shaderexample_SOURCES = main.cc
shaderexample_LDADD = libglex.la

lib_LTLIBRARIES = libglex.la
libglex_la_SOURCES = GameWorld.cc GameAssetManager.cc CubeAsset.cc DiamondAsset.cc GroundAsset.cc LeavesAsset.cc PyramidAsset.cc GrassAsset.cc GameAsset.cc BoundingBox.cc Camera.cc GameLoop.cc

AM_CPPFLAGS = -DGL_GLEXT_PROTOTYPES -DGL3_PROTOTYPES
AM_CPPFLAGS += -std=c++11 -I/usr/include/python2.7
AM_CPPFLAGS += $(gl_CFLAGS) $(glew_CFLAGS) $(sdl2_CFLAGS) $(BOOST_CPPFLAGS)

LDFLAGS = -framework OpenGL -framework GLUT -lSDL2 -lboost_system -lboost_python -Wl,-rpath,'$$ORIGIN/.libs'
LIBS += $(gl_LIBS) $(glew_LIBS) $(sdl2_LIBS) $(BOOST_THREAD_LIBS) $(BOOST_PROGRAM_OPTIONS_LIBS)

#-lpython2.7#
