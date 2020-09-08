    global ft_strdup
    extern malloc
    extern ft_strlen
    extern ft_strcpy
    section .text

ft_strdup:
    cmp     rdi, 0x0
    je      isnull
    call    ft_strlen
    inc     rax
    push    rdi
    mov     rdi, rax
    call    malloc
    cmp     rax, 0x0
    je      isnull
    pop     rdi
    push    rsi
    mov     rsi, rdi
    mov     rdi, rax
    call    ft_strcpy
    pop     rsi
    ret

isnull:
    mov rax, 0x0
    ret