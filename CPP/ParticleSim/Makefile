
LDLIBS=-lSDL2 -lpthread -lm
LDFLAGS= -L/home/k/lib,-rpath,/home/k/lib

INCLUDE=./Systems ./Types ./Factorized ./constantHeaders.
BINARY=ParticleSim
SOURCES=./Factorized ./resourcePaths  .  ./Systems  ./Types

CURRDIR=echo `pwd`

CXX= g++
DEPFLAGS= -MP -MD

CXXFLAGS= -Wall -DPROGRAMPATHAUX="$(CURRDIR)" -std=gnu++11 -Wextra -g $(foreach D, $(INCLUDE), -I$(D)) $(DEPFLAGS) `sdl2-config --libs`

SOURCEFILES=$(foreach D,$(SOURCES), $(wildcard $(D)/*.cpp))

OBJECTS=$(patsubst %.cpp,%.o,$(SOURCEFILES))

DEPFILES= $(patsubst %.cpp,%.d,$(SOURCEFILES))


all: $(BINARY)
	echo $(LDLIBS)
	echo $(CURRDIR)


$(BINARY): $(OBJECTS)
	$(CXX)  $(CXXFLAGS) -o $@ $^ $(LDLIBS) $(LDFLAGS)


%.o:%.c
	$(CXX)  $(CXXFLAGS) -c -o $@ $<  $(LDLIBS)  $(LDFLAGS)
	echo $(CXXFLAGS)
clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)
