

LDLIBS=-lSDL2 -lSDL2_ttf -lpthread -lm -lSDL2_image


INCLUDE= ./Includes .
BINARY= newLust
SOURCES= ./Sources .

CURRDIR=echo `pwd`

CXX= g++
DEPFLAGS= -MP -MD

CXXFLAGS= -Wall -DPROGRAMPATHAUX="$(CURRDIR)" -std=gnu++11 -Wextra -g $(foreach D, $(INCLUDE), -I$(D)) $(DEPFLAGS) `sdl2-config --libs`

SOURCEFILES=$(foreach D,$(SOURCES), $(wildcard $(D)/*.cpp))

OBJECTS=$(patsubst %.cpp,%.o,$(SOURCEFILES))

DEPFILES= $(patsubst %.cpp,%.d,$(SOURCEFILES))

RESOURCEFILES= $(wildcard ./resources/embeded/*.res)


RESOBJECTS=$(patsubst %.res,%.o,$(RESOURCEFILES))


all: $(BINARY)
	echo $(LDLIBS)
	echo $(CURRDIR)


$(BINARY): $(OBJECTS) $(RESOBJECTS)
	$(CXX) -g  $(CXXFLAGS) -o $@ $^ $(LDLIBS)


%.o:%.c
	$(CXX)  $(CXXFLAGS) -c -o $@ $<  $(LDLIBS)
	echo $(CXXFLAGS)
clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)



objs: $(RESOBJECTS)
	echo $(RESOBJECTS)

%.o:%.res
	ld -r -b binary -o $@ $<

cleanres:
	rm -rf $(RESOBJECTS)





