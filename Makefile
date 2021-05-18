COMPILERFLAGS=-Wall -Wextra -Werror
COMPILERFLAGSTEST=$(COMPILERFLAGS)
LINKERFLAGS=
LIBRARIES=
LIBRARIESTEST=-lcppunit
COMPILER=g++
LINKER=g++
SOURCEFILESTEST=$(wildcard *test.cpp)
SOURCEFILESWITHTESTFILES=$(wildcard *.cpp)
SOURCEFILES=$(filter-out $(SOURCEFILESTEST) testrunner.cpp main.cpp, $(SOURCEFILESWITHTESTFILES))
OBJECTFILES=$(addprefix build/,$(patsubst %.cpp,%.o,$(SOURCEFILES)))
OBJECTFILESTEST=$(addprefix build/,$(patsubst %.cpp,%.o,$(SOURCEFILESTEST)))

all: build/testrunner build/planetcannons

clean:
	rm -fR build

tests: build/testrunner
	./build/testrunner

build/guard:
	mkdir build
	touch build/guard

build/%.o: %.cpp build/guard
	$(COMPILER) -c $(COMPILERFLAGS) $< -o $@

build/testrunner: $(OBJECTFILESTEST) $(OBJECTFILES) build/testrunner.o build/guard
	$(LINKER) $(LINKERFLAGS) build/testrunner.o $(OBJECTFILESTEST) $(OBJECTFILES) $(LIBRARIES) $(LIBRARIESTEST) -o $@

build/planetcannons: $(OBJECTFILES) build/main.o build/guard
	$(LINKER) $(LINKERFLAGS) build/main.o $(OBJECTFILES) $(LIBRARIES) -o $@

.PHONY: all clean