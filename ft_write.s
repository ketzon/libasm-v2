section .text
global ft_write
extern __errno_location

ft_write:
    mov rax, 1
    syscall    ;call le kernel et renvoi dans rax
    cmp rax, 0 ;rax contient nombre octet lu, si < 0 (error)
    jl error
    ret

error:
    neg rax ;le systeme renvoie la valeur en negatif errno a besoin de la valeur en positif
    mov r8, rax
    call __errno_location wrt ..plt 
    mov [rax], r8 ;met la valeur de r8 a l'adresse pointe par rax (*errno = code_erreur)
    mov rax, -1 ;return -1 en cas d'erreur
    ret
