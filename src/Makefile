SOURCES =	camera.cc
OBJECTS	=	$(SOURCES:.cc=.o)
TARGET	=	libcamera
DIR = ../

all: lib_sta

lib_sta:
	g++ -c $(SOURCES)
	ar cr $(DIR)$(TARGET).a $(OBJECTS)

lib_dyn:
	g++ -c -fPIC $(SOURCES)
	g++ -shared -o $(DIR)$(TARGET).so $(OBJECTS)
