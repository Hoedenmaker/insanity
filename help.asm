section .bss
	buffer resb "0"
	negr resb 4	
section .text
	global _start

_start:
	mov edi, 0
	mov eax, 1
	mov [negr], eax
	call cursor
	
	mov edi, 34
	mov eax, 58
	mov [negr], eax
	call cursor
	
	mov eax, 1
	xor ebx, ebx
	int 0x80

cursor:
	add edi, 48
	mov [buffer], edi
	
	mov eax, 4
	mov ebx, 1
	mov ecx, buffer
	mov edx, 10
	int 0x80	

	inc edi
	
	cmp [negr], edi
	jle cursor
	
	ret
