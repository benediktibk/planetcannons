COMPILERFLAGS=-Wall -Wextra -Werror -MMD -std=c++20 -g -O0 -Isrc/
COMPILERFLAGSTEST=$(COMPILERFLAGS)
LINKERFLAGS=-g
LIBRARIES=-lglfw -lGL -lGLEW
LIBRARIESTEST=-lcppunit
COMPILER=g++
LINKER=g++
SOURCEFILESTEST=$(shell find src/ -type f -name '*Test.cpp') $(shell find src/ -type f -name '*Mock.cpp')
SOURCEFILESWITHTESTFILES=$(shell find src/ -type f -name '*.cpp')
SOURCEFILES=$(filter-out $(SOURCEFILESTEST) src/testrunner.cpp src/main.cpp, $(SOURCEFILESWITHTESTFILES))
OBJECTFILES=$(addprefix build/,$(patsubst %.cpp,%.o,$(SOURCEFILES:src/%=%)))
OBJECTFILESTEST=$(addprefix build/,$(patsubst %.cpp,%.o,$(SOURCEFILESTEST:src/%=%)))
DEPENDENCIES=$(OBJECTFILES:%.o=%.d) $(OBJECTFILESTEST:%.o=%.d) build/main.d build/testrunner.d
SHADERFILES=$(shell find src/ -type f -name '*.vert') $(shell find src/ -type f -name '*.frag') $(shell find src/ -type f -name '*.tesc') $(shell find src/ -type f -name '*.tese') $(shell find src/ -type f -name '*.geom') $(shell find src/ -type f -name '*.comp')
SHADERTARGETFILES=$(addprefix build/,$(SHADERFILES:src/graphics/%=%))
SHADERCOMPILER=/usr/bin/glslangValidator

all: build/testrunner build/planetcannons

clean:
	rm -fR build

-include $(DEPENDENCIES)

tests: build/testrunner
	./build/testrunner

run: build/planetcannons
	cd build && ./planetcannons

build/guard:
	mkdir -p build
	mkdir -p build/physics
	mkdir -p build/game
	mkdir -p build/graphics
	mkdir -p build/math
	mkdir -p build/utils
	touch build/guard

build/%.o: src/%.cpp build/guard Makefile
	$(COMPILER) -c $(COMPILERFLAGS) $< -o $@

build/%.vert: src/graphics/%.vert build/guard Makefile
	$(SHADERCOMPILER) $<
	cp $< $@

build/%.frag: src/graphics/%.frag build/guard Makefile
	$(SHADERCOMPILER) $<
	cp $< $@
	
build/%.tesc: src/graphics/%.tesc build/guard Makefile
	$(SHADERCOMPILER) $<
	cp $< $@
	
build/%.tese: src/graphics/%.tese build/guard Makefile
	$(SHADERCOMPILER) $<
	cp $< $@
	
build/%.geom: src/graphics/%.geom build/guard Makefile
	$(SHADERCOMPILER) $<
	cp $< $@
	
build/%.comp: src/graphics/%.comp build/guard Makefile
	$(SHADERCOMPILER) $<
	cp $< $@

build/testrunner: $(OBJECTFILESTEST) $(OBJECTFILES) build/testrunner.o build/guard
	$(LINKER) $(LINKERFLAGS) build/testrunner.o $(OBJECTFILESTEST) $(OBJECTFILES) $(LIBRARIES) $(LIBRARIESTEST) -o $@

build/planetcannons: $(OBJECTFILES) $(SHADERTARGETFILES) build/main.o build/guard
	$(LINKER) $(LINKERFLAGS) build/main.o $(OBJECTFILES) $(LIBRARIES) -o $@

.PHONY: all clean