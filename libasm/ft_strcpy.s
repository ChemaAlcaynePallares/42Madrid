    global ft_strcpy
    section .text
ft_strcpy:
    mov rcx, 0x0
    cmp rsi, 0
    je return
    jmp copy

increment:
    inc rcx

copy:
    mov dl, byte [rsi + rcx]
    mov byte [rdi + rcx], dl
    cmp dl, 0
    jne increment

return:
    mov rax, rdi
    ret