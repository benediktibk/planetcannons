COMPILERFLAGS=-Wall -Wextra -Werror -MMD -std=c++20 -g -O0
COMPILERFLAGSTEST=$(COMPILERFLAGS)
LINKERFLAGS=-g
LIBRARIES=-lglfw -lGL -lGLEW
LIBRARIESTEST=-lcppunit
COMPILER=g++
LINKER=g++
SOURCEFILESTEST=$(wildcard *Test.cpp) $(wildcard *Mock.cpp)
SOURCEFILESWITHTESTFILES=$(wildcard *.cpp)
SOURCEFILES=$(filter-out $(SOURCEFILESTEST) testrunner.cpp main.cpp, $(SOURCEFILESWITHTESTFILES))
OBJECTFILES=$(addprefix build/,$(patsubst %.cpp,%.o,$(SOURCEFILES)))
OBJECTFILESTEST=$(addprefix build/,$(patsubst %.cpp,%.o,$(SOURCEFILESTEST)))
DEPENDENCIES=$(OBJECTFILES:%.o=%.d) $(OBJECTFILESTEST:%.o=%.d) build/main.d build/testrunner.d
SHADERFILES=$(wildcard *.vert) $(wildcard *.frag) $(wildcard *.tesc) $(wildcard *.tese) $(wildcard *.geom) $(wildcard *.comp)
SHADERTARGETFILES=$(addprefix build/,$(SHADERFILES))
SHADERCOMPILER=/usr/bin/glslangValidator

all: build/testrunner build/planetcannons

clean:
	rm -fR build

-include $(DEPENDENCIES)

tests: build/testrunner
	./build/testrunner

build/guard:
	mkdir -p build
	touch build/guard

build/%.o: %.cpp build/guard Makefile
	$(COMPILER) -c $(COMPILERFLAGS) $< -o $@

build/%.vert: %.vert build/guard Makefile
	$(SHADERCOMPILER) $<
	cp $< $@

build/%.frag: %.frag build/guard Makefile
	$(SHADERCOMPILER) $<
	cp $< $@
	
build/%.tesc: %.tesc build/guard Makefile
	$(SHADERCOMPILER) $<
	cp $< $@
	
build/%.tese: %.tese build/guard Makefile
	$(SHADERCOMPILER) $<
	cp $< $@
	
build/%.geom: %.geom build/guard Makefile
	$(SHADERCOMPILER) $<
	cp $< $@
	
build/%.comp: %.comp build/guard Makefile
	$(SHADERCOMPILER) $<
	cp $< $@

build/testrunner: $(OBJECTFILESTEST) $(OBJECTFILES) build/testrunner.o build/guard
	$(LINKER) $(LINKERFLAGS) build/testrunner.o $(OBJECTFILESTEST) $(OBJECTFILES) $(LIBRARIES) $(LIBRARIESTEST) -o $@

build/planetcannons: $(OBJECTFILES) $(SHADERTARGETFILES) build/main.o build/guard
	$(LINKER) $(LINKERFLAGS) build/main.o $(OBJECTFILES) $(LIBRARIES) -o $@

.PHONY: all clean