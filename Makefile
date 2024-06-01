CC = gcc
OPT = -O3
RAYLIB_INCLUDE = ./raylib/include/
RAYLIB_LIB = ./raylib/lib
INCLUDE = ./include/
PROGRAM_NAME = game_of_life
CFLAGS = -Wall -Wextra -pedantic $(OPT) -I$(INCLUDE) -I$(RAYLIB_INCLUDE)
LDFLAGS = -L$(RAYLIB_LIB) -Wl,-rpath=$(RAYLIB_LIB) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

OBJ = obj/main.o obj/array.o

all: game_of_life

obj/%.o: src/%.c 
	$(CC) -c $< $(CFLAGS) -o $@ 

$(PROGRAM_NAME): $(OBJ) 
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) obj/*.o game_of_life

run: $(PROGRAM_NAME)
	./game_of_life
