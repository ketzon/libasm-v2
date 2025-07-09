; ===== GENERAL INFOS =====
; en assembleur c'est toujours une instruction et ensuite les operandes. exemple: move rax, 0
; on copie la valeur 0 dans le register rax (register accumlator extention "register de return")
; The square brackets [] are used to dereference an address.
; return always return RAX

; ==== EXEMPLE OF STRLEN FONCTION IN C ====
; int ft_strlen(char *str) 
; {
;     int i;
;     i = 0;
;     while (str[i] != '\0')
;     {
;          i++;
;     }
;     return i;
; }

section .text           ; Section de code
global ft_strlen        ; permet d'utiliser strlen dans un code C (c'est un export)
ft_strlen:
    mov rcx, 0 ; same as int i = 0
.loop:
    cmp byte [rdi + rcx], 0     ; same as str[i] != '\0' cmp met a jour les flags du proc
    je .end                     ;fin de la boucle
    inc rcx                     ;same as i++
    jmp .loop                   ;continuer de boucler
.end:
    mov rax, rcx
    ret 
