CC = gcc-9
CF = -Wall -Wextra -pedantic
OBJDIR = ./obj/

all: main
	
$(OBJDIR)funcs.o: funcs.c
	$(CC) $(CF) funcs.c -c -o $@

$(OBJDIR)main.o: main.c
	$(CC) $(CF) main.c -c -o $@ 

$(OBJDIR)error.o: error.c
	$(CC) $(CF) error.c -c -o $@ 

main: $(OBJDIR)funcs.o $(OBJDIR)main.o $(OBJDIR)error.o
	$(CC) $(CF) $(OBJDIR)funcs.o $(OBJDIR)main.o $(OBJDIR)error.o -o $@

clean:
	rm -rf ./obj/*.o main
