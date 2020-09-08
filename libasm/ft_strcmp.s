    global ft_strcmp
    section .text
ft_strcmp:
    loop:
    mov     al, byte [rdi]
    mov     bl, byte [rsi]
    cmp     al, 0
    je final
    cmp     bl, 0
    je final
    cmp     al, bl
    jne final
    jl low
    jg greater
    inc rdi
    inc rsi
    jmp loop

low:
    mov     rax, -1
    ret
greater:
    mov     rax, 1
    ret

equal:
    mov     rax, 0
    ret

final:
    cmp al, bl
    je equal
    jl low
    jg greater

