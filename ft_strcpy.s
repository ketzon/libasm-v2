; ==== ft_strcpy in c ====
; char *ft_strcpy(char *dest, char *src)
; {
;     int i;
;     i = 0;
;     if (!src)
;     {
;         return NULL;
;     }
;     while (src[i])
;     {
;         dest[i] = src[i];
;         i++;
;     }
;     return dest;
; }

section .text
global ft_strcpy
ft_strcpy:
    mov rax, rdi ;ajoute la dest dans la condition de return
loop:
    mov bl, [rsi] ;moove le character de la string source dans un register de 1octer(8bit) pour 1 character
    mov [rdi], bl ;copie le character dans la dest
    inc rdi ;incremente la dest
    inc rsi ;incremente la source
    test bl, bl ;test si bl n'est pas a 0. Ajoute la valeur dans le flag ZF (0 si on est en fin de string, est 1 si c'est un character)
    jnz loop ;continue de boucler si ZF est a 1, sinon on sort et return RAX, qui est notre nouvelle dest
    ret 
