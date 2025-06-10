section .bss
	buffer resb 100	

section .data
	buffer2 db "0"

section .text
	global _start

_start:	
	call input
	mov eax, buffer
	call input
	mov esi, buffer
	call input
	mov edi, buffer

	call output

	mov eax, 1
	mov ebx, edi
	int 0x80

input:
	mov eax, 3
	mov ebx, 2
	mov ecx, buffer 
	mov edx, 100
	int 0x80

	ret

output:
	mov [buffer2], edi

	mov eax, 4 
	mov ebx, 1
	mov ecx, buffer2 
	mov edx, 100
	int 0x80

	ret
plus:
	add edi, esi
	
	ret

chlen:	
	cmp eax, ebx
	je plus

	ret
