section .text
global ft_strcmp

ft_strcmp:
	xor	rcx,rcx
	xor	rdx,rdx
	cmp	rdi, 0
	je	return_if_null
	cmp	rsi, 0
	je	return_if_null
	jmp	if_str_end
compare_str:
	mov	dl, BYTE [rsi + rcx]
	cmp	dl, BYTE [rdi + rcx]
	jne	str_end
add:
	inc rcx
if_str_end:
	cmp	BYTE [rdi + rcx], 0
	je	str_end
	cmp	BYTE [rsi + rcx], 0
	je	str_end
	jmp	compare_str
str_end:
	mov	dl, BYTE [rdi + rcx]
	sub	dl, BYTE [rsi + rcx]
	cmp	dl, 0
	je	equal
	jl	minus
	jg	plus
return_if_null:
	cmp	rdi,rsi
	je	equal
	jl	minus
	jg	plus
equal:
	mov	rax, 0
	ret
minus:
	mov	rax, -1
	ret
plus:
	mov	rax, 1
	ret
