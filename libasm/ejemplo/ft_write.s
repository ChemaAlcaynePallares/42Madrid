section .text
	global ft_write
	extern __errno_location

ft_write:
	cmp rdi, 0
	je error_return
	mov rax, 1
	syscall
	jc error
	ret
error:
	push rdi
	mov rdi, rax
	call __errno_location
	mov [rax], rdi
	pop rdi
error_return:
	mov rax, -1
	ret
