build:
	nasm -f elf zaloop.asm -o z.o
	ld -m elf_i386 -s z.o -o z
	./z	
