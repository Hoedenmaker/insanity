build:
	gcc src/*.c -o svc -I include/ -L lib/x64 -lSDL3 -lwinmm -mwindows