section .text
global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

; version sans push and pop (plus rapide)
ft_strdup:
    call    ft_strlen
    inc rax
    mov r15, rdi ;stock value dans un register temp qui n'est pas utiliser par les appel system
    ; push rdi
    mov rdi, rax
    call malloc wrt ..plt
    cmp rax, 0
    jz  error
    mov rdi, rax
    mov rsi, r15
    ; pop rsi
    call ft_strcpy
    ret
error:
    ret

