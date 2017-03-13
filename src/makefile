UNAME = $(shell uname)


CC 		= g++
CFLAGS 	= -Wall -m64
LDFLAGS =

CXXDIR = ../bin/cxxtest
CXXTEST = $(CXXDIR)/bin/cxxtestgen
CXXFLAGS = --error-printer --abort-on-fail --have-eh

##
# List of cpp files to be compiled
# Note, if you add any cpp files to your project, you must also add them here
##
CPPFILES += main.cpp 
CPPFILES += BaseGfxApp.cpp 
CPPFILES += Simulation.cpp
CPPFILES += PhysicalObjectClass.cpp
CPPFILES += RobotClass.cpp
CPPFILES += TargetClass.cpp
CPPFILES += ObstacleClass.cpp
CPPFILES += EnvironmentClass.cpp
CPPFILES += RenderingWindowClass.cpp

##
# Lists all the cpp files in /src
# Note, this means you can make from /src, /lib, or /bin
##
SOURCES=$(addprefix ../src/,  $(CPPFILES))

OBJECTS = $(addprefix ../bin/,  $(CPPFILES:.cpp=.o)) 

GLUI = glui

##
# Linking the GLUI libraries
##
LINK_LIBS += -L../lib/$(GLUI)/lib/ -lglui
INCLUDE = -I../lib/$(GLUI)/include/ -I../src

##
# Linking GLUT and OpenGl for Mac
##
ifeq ($(UNAME), Darwin)
	LINK_LIBS += -framework glut -framework opengl
	EXECUTABLE = ../bin/gorobot
	TESTRUNNER = ../bin/testrobot
##
# Linking GLUT and OpenGl for Linux
##
else
	ifeq ($(UNAME), Linux)
		LINK_LIBS += -lglut -lGL -lGLU -lpthread
		EXECUTABLE = ../bin/gorobot
		TESTRUNNER = ../bin/testrobot
##
# Linking GLUT and OpenGl for Windows
# Note, you must have freeGlut installed; see the Resource page for details
##
	else 
		GLUTINCLUDEPATH = C:\Dev-Cpp\mingw32\freeglut\include\
		GLUTLIBPATH = C:\Dev-Cpp\mingw32\freeglut\lib\
		LINK_LIBS += -L$(GLUTLIBPATH) -lfreeglut -lopengl32 -Wl,--subsystem,windows
		INCLUDE += -I$(GLUTPATH)
		EXECUTABLE = gorobot.exe

	endif
endif

##
# Sets up the /bin folder, checks for all cpp files, and compiles the executable
##
all: setup $(SOURCES) gorobot

setup:
	mkdir -p ../bin

gorobot: $(GLUI) $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(LINK_LIBS) -o $(EXECUTABLE)

test.cpp: RobotClassTests.h ObstacleClassTests.h TargetClassTests.h PhysicalObjectClassTests.h EnvironmentClassTests.h
	$(CXXTEST) $(CXXFLAGS) -o test.cpp RobotClassTests.h ObstacleClassTests.h TargetClassTests.h PhysicalObjectClassTests.h EnvironmentClassTests.h

testrobot: test.cpp $(OBJECTS)
	$(CC) -I$(CXXDIR) $(LINK_LIBS) -o $(TESTRUNNER) $(OBJECTS)

tests: testrobot
	$(TESTRUNNER)

##
# This creates the object files in the /bin folder
##
../bin/%.o: ../src/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	\rm -rf test.cpp $(OBJECTS) $(EXECUTABLE) $(TESTRUNNER)
	\rm *~
	 $(MAKE)  -C ../lib/$(GLUI) clean

$(GLUI):
	$(MAKE) -C ../lib/$(GLUI) all
