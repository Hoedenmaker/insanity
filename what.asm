section .bss
	buffer resb 10

section .data
	msg db "fuck"
	len equ $ - msg

section .text
	global _start

_start:
	mov eax, 543 
	mov edi, buffer + 9
	mov byte [edi], 0

	call fuck
	call print

	mov eax, 1
	xor ebx, ebx
	int 0x80
fuck:
	xor edx, edx
	dec edi
	mov ecx, 10
	div ecx
	add dl, '0'
	mov [edi], dl
	test eax, eax
	jnz fuck

	ret
print:
	mov eax, 4
	mov ebx, 1
	mov ecx, edi
	mov edx, 100
	int 0x80

	ret
