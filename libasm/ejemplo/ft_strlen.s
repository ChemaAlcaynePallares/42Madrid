section .text
global ft_strlen

ft_strlen:
	xor rax, rax
	jmp if
add:
	inc rax
if:
	cmp BYTE [rdi + rax], 0
	jne add
return: 
	ret
