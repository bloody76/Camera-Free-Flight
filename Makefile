
all:
	make lib_dyn -C src/ 

lib_dyn:
	make lib_dyn -C src/

lib_sta:
	make lib_sta -C src/

sample: lib_dyn
	make sample -C sample/

clean:
	@find . -name CameraSample -exec rm {} \;
	@find . -name libcamera.so -exec rm {} \;
	@find . -name "*.o" -exec rm {} \;

