
all:
	make lib_sta -C src/

lib_dyn:
	make lib_dyn -C src/

lib_sta:
	make lib_sta -C src/

sample: lib_sta
	make sample -C sample/

doc:
	make -C doc/

clean:
	@find . -name CameraSample -exec rm {} \;
	@find . -name libcamera.so -exec rm {} \;
	@find . -name libcamera.a -exec rm {} \;
	@find . -name "*.o" -exec rm {} \;
	@make clean -C doc/

.PHONY: doc all lib_sta lib_dyn sample
