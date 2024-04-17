CC = gcc
CFLAGS = -Wall -Wextra -pedantic -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
INCLUDE = ./include/

OBJ = obj/main.o obj/array.o

all: game_of_life

obj/%.o: src/%.c
	$(CC) -c $< -I$(INCLUDE) -o $@ $(CFLAGS)

game_of_life: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	$(RM) obj/*.o game_of_life
