build:
	gcc src/*.c -o svchost -I include/ -L lib/x64 -lSDL3 -mwindows