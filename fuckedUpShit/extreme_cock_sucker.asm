section .bss
	num resb 1
	buff_1 resd 1
	buff_2 resd 1
	buffer resb 12
	buffer_a resb 12
	extreme_cock_sucker resb 12

section .text
	global _start

_start:
	mov eax, 3
	mov ebx, 0 
	mov ecx, buffer
	mov edx, 11
	int 0x80

	mov esi, buffer
	call str_to_int
	
	add eax, 5

	mov edi, extreme_cock_sucker + 11
	mov byte [edi], 0
	dec edi
	call int_to_str
	
	mov eax, extreme_cock_sucker
	add eax, 11
	sub eax, edi
	mov edx, eax
	mov eax, 4
	mov ebx, 1
	mov ecx, edi
	int 0x80	

	mov eax, 1
	xor ebx, ebx
	int 0x80

	ret

str_to_int:
	xor eax, eax
	xor ecx, ecx

.loop:
	movzx edx, byte [esi]
	test edx, edx
	jz .done
	cmp edx, 10
	je .done
	sub edx, '0'
	cmp edx, 9
	ja .done
	imul eax, eax, 10
	add eax, edx
	inc esi
	jmp .loop
	ret

.done:
	ret

int_to_str:
	mov ecx, 10

.reverse_loop:
	xor edx, edx
	div ecx
	add dl, '0'
	mov [edi], dl
	dec edi
	test eax, eax
	jnz .reverse_loop
	
	inc edi

	ret
