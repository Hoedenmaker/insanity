.section .data
	buffer:
		.ascii "0\n"

.section .text
.globl _start

_start:
	movl $5, %esi
	movl $4, %edi
	addl %esi, %edi

	addl $48, %edi
	movl %edi, buffer

	movl $4, %eax
	movl $1, %ebx
	movl $buffer, %ecx
	movl $2, %edx
	int $0x80

	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80	
