LDLIBS= -lmenu -lncurses -lpthread -lm

INCLUDE= ./Include
BINARY=TermaPet
SOURCES= . ./Sources
RESDIR= ./resource

CURRDIR=echo `pwd`

CC= gcc
DEPFLAGS= -MP -MD

CFLAGS= -Wall -DPROGRAMPATHAUX="$(CURRDIR)"  -Wextra -g $(foreach D, $(INCLUDE), -I$(D)) $(DEPFLAGS) `sdl2-config --libs`

SOURCEFILES=$(foreach D,$(SOURCES), $(wildcard $(D)/*.c))


RESOURCEFILES=$(wildcard $(RESDIR)/*.o)


OBJECTS=$(patsubst %.c,%.o,$(SOURCEFILES))

ALLMODULES= $(RESOURCEFILES) $(OBJECTS)

DEPFILES= $(patsubst %.c,%.d,$(SOURCEFILES))


all: $(BINARY)
	echo $(LDLIBS)
	echo $(CURRDIR)


$(BINARY): $(OBJECTS)
	$(CC) -g -v  $(CFLAGS) -o  $@ $^ $(RESOURCEFILES)  $(LDLIBS)


%.o:%.c
	$(CC)  $(CFLAGS) -c -o $@ $<  $(LDLIBS)
	echo $(CFLAGS)

clean:
	rm -rf $(BINARY) $(ALLMODULES) $(DEPFILES)
