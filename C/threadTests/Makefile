BINARY= threadTests

LDLIBS=  -lm -lpthread
INCLUDE= ./Includes .
SOURCES= . ./Sources
RESDIR= ./resources
 
CURRDIR=echo `pwd`
 
CC= clang
DEPFLAGS= -MP -MD

THREAD_DEBUGGING= -fsanitize=thread
MEMORY_DEBUGGING= -fsanitize=address
NO_DEBUGGING=
DEBUGGING_MODE= $(MEMORY_DEBUGGING)
CFLAGS= -Wall $(DEBUGGING_MODE)  -DPROGRAMPATHAUX="$(CURRDIR)" -Wextra -g $(foreach D, $(INCLUDE), -I$(D)) $(DEPFLAGS) 
SOURCEFILES=$(foreach D,$(SOURCES), $(wildcard $(D)/*.c))
INCLUDEFILES=$(foreach D,$(INCLUDE), $(wildcard $(D)/*.h))


RESOURCEFILES=$(wildcard $(RESDIR)/*.o)


OBJECTS=$(patsubst %.c,%.o,$(SOURCEFILES))

ALLMODULES= $(RESOURCEFILES) $(OBJECTS)

DEPFILES= $(patsubst %.c,%.d,$(SOURCEFILES))

all: $(BINARY)
	echo $(LDLIBS)
	echo $(CURRDIR)


$(BINARY): $(OBJECTS)
	$(CC) -g -v  $(CFLAGS) -o  $@ $^ $(RESOURCEFILES)  $(LDLIBS)


%.o:%.c %.h
	$(CC) -g  $(CFLAGS) -c -o $@ $<  $(LDLIBS)
	echo $(CFLAGS)

clean:
	rm -rf $(BINARY) $(ALLMODULES) $(DEPFILES)
