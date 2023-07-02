LIBS=-lSDL2 -lpthread -lm
INCLUDE=./Systems ./Types ./Factorized ./constantHeaders .
BINARY=ParticleSim
SOURCES=./Factorized ./resourcePaths  .  ./Systems  ./Types


CPP=g++
DEPFLAGS=-MP -MD

FLAGS=-Wall -Wextra -g $(foreach D, $(INCLUDE), -I$(D)) $(DEPFLAGS)

SOURCEFILES=$(foreach D,$(SOURCES), $(wildcard $(D)/*.cpp))

OBJECTS=$(patsubst %.cpp,%.o,$(SOURCEFILES))

DEPFILES= $(patsubst %.cpp,%.d,$(SOURCEFILES))


all: $(BINARY)


$(BINARY): $(OBJECTS)
	$(CPP)   -o $@ $^ $(LIBS)


%.o:%.c
	$(CPP) $(LIBS) $(FLAGS) -c -o $@ $<
	
clean: 
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)
