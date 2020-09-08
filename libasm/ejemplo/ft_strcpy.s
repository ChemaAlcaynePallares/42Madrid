section .text
global ft_strcpy

ft_strcpy:
	xor rcx, rcx ; i
	xor rdx, rdx ; temp
	cmp rsi, 0
	jz	exit
	jmp	cpy
add:
	inc rcx
cpy:
	mov dl, BYTE [rsi + rcx]
	mov BYTE [rdi + rcx], dl
	cmp BYTE [rsi + rcx], 0
	jne add
return:
	mov rax, rdi
	ret
exit:
	mov rax, rsi
	ret
