SOURCES = main.cc
OBJECTS = $(SOURCES:.cc=.o)
TARGET = CameraSample
DIR = ../
LIBS = $(shell sdl-config --libs) -lGL -lGLU  -L../ -lcamera

sample:
	g++ -c $(SOURCES)
	g++ -o $(DIR)$(TARGET) $(OBJECTS) $(LIBS)

