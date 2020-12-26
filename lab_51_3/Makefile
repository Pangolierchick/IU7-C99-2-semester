CC = gcc-9
CF = -g -Wall -pedantic -Wextra -Werror
OBJDIR = ./obj/

all: main

$(OBJDIR)main.o: main.c 
	$(CC) $(CF) main.c -c -o $@

$(OBJDIR)funcs.o :funcs.c
	$(CC) $(CF) funcs.c -c -o $@

$(OBJDIR)error.o: error.c
	$(CC) $(CF) error.c -c -o $@ 

main: $(OBJDIR)funcs.o $(OBJDIR)main.o $(OBJDIR)error.o
	$(CC) $(CF) $(OBJDIR)main.o $(OBJDIR)funcs.o $(OBJDIR)error.o -o $@

clean:
	rm -rf $(OBJDIR)*.o main

	
