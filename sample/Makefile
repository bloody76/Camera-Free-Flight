SOURCES = main.cc
OBJECTS = $(SOURCES:.cc=.o)
STA_LIBS = libcamera.a
TARGET = CameraSample
DIR = ../
LIBS = $(shell sdl-config --libs) -lGL -lGLU

sample:
	g++ -c $(SOURCES)
	g++ -o $(DIR)$(TARGET) $(OBJECTS) $(DIR)$(STA_LIBS) $(LIBS)

