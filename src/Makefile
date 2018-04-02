CC     = g++
CFLAGS = -c -Wall 
LINKER_FLAGS = -lSDL2 -lSDL2_image $(pkg-config --cflags --libs sdl2)

all: game

game: main.o Game.o TextureManager.o GameObject.o
	$(CC) main.o Game.o TextureManager.o GameObject.o -o ../game $(LINKER_FLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Game.o: Game.cpp Game.h
	$(CC) $(CFLAGS) Game.cpp

TextureManager.o: TextureManager.cpp TextureManager.h
	$(CC) $(CFLAGS) TextureManager.cpp

GameObject.o: GameObject.cpp GameObject.h
	$(CC) $(CFLAGS) GameObject.cpp

clean:
	rm -rf *o game && clear