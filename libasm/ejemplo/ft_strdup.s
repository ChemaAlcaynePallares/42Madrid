section	.text
global	ft_strdup
extern	malloc

ft_strdup:
	cmp	rdi, 0
	je	if_null
	xor	rcx, rcx
	jmp	len
if_null:
	xor	rax, rax
	ret
add_len:
	inc	rcx
len:
	cmp	BYTE [rdi + rcx], 0
	jne	add_len
	inc	rcx
make_malloc:
	push	rdi
	mov	rdi, rcx
	call	malloc
	pop	rdi
	cmp	rax, 0
	je	if_null
copy_initialize:
	xor	rcx, rcx
	xor	rdx, rdx
	jmp	copy
add:
	inc	rcx
copy:
	mov	dl, BYTE [rdi + rcx]
	mov	BYTE [rax + rcx], dl
	cmp	dl, 0
	jne	add
	ret

