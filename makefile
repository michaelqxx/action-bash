# Makefile
CC=gcc
LDFLAGS=-lcurses
OBJ=action-bash.o

#	
%.o:%.c
	$(CC) -c -o $@ $^
	
action-bash: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
		
all: action-bash

clean:
	rm *.o action-bash
