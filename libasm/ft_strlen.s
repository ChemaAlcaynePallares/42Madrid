    global ft_strlen
    section .text
ft_strlen:
    mov     rax, 0x0
    loop:
        cmp byte [rdi + rax], 0x0
        jz fin
        inc rax
        jmp loop
    fin:
    ret
