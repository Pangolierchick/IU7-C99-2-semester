CC = gcc
CF = -Wall -Wextra -std=c99 -pedantic
OBJ = ./obj
crobj = mkdir -p $(OBJ)

OBJLIST = $(OBJ)/main.o $(OBJ)/error.o $(OBJ)/funcs.o

all: main

$(OBJ)/error.o: error.c
	$(crobj)
	$(CC) $(CF) -c $< -o $@

$(OBJ)/funcs.o: funcs.c
	$(crobj)
	$(CC) $(CF) -c $< -o $@

$(OBJ)/main.o: main.c
	$(crobj)
	$(CC) $(CF) -c $< -o $@

main: $(OBJ)/main.o $(OBJ)/error.o $(OBJ)/funcs.o
	$(CC) $(CF) $(OBJ)/main.o $(OBJ)/error.o $(OBJ)/funcs.o -o $@

clean:
	rm -rf ./main $(OBJ)/*.o $(OBJ)
