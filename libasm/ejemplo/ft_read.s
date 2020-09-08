section .text
	global	ft_read
	extern	__errno_location

ft_read:
	mov rax, 0
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
	
