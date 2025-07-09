; #include "../header.h"

; //s1 = "hello"
; //s2 = "world"
; int ft_strcmp(const char *s1, const char *s2){
;     int i = 0;
;     while (s1[i] && s2[i]) {
;         if(s1[i] != s2[i])
;             return (s1[i] - s2[i]);
;         i++;
;     }
;     return (s1[i] - s2[i]);
; }


section .text
global ft_strcmp ;hello ;hello

ft_strcmp:
loop:
    mov al, [rdi] ;je prend un character dans rdi et je le moove dans al (sub register de 1byte)
    mov bl, [rsi] ;same pour la source
    cmp al, bl    ;compare les deux character
    jne not_equal ;jump si ZF=0 (si les character sont different CMP met a jour ZF=0) 
    test al,al    ;met a jour les flags du processeur
    jz equal      ;jump si ZF=1 donc al a 0 (fin de chaine)
    inc rdi       ;incremente rdi
    inc rsi       ;incremente rsi
    jmp loop     ;continue d'incerementer et de boucler si valeur est equal (zf=1 et pas de character null)
not_equal:
    movzx eax, al ;etend al dans rax (8bit -> 32bits pour le return)
    movzx ebx, bl ;etend bl dans rax
    sub eax, ebx  ;calcul la diff et return eax
    ret

equal:
    xor eax,eax ;met a zero de la maniere la plus fast possible
    ret


; ft_strcmp:
; loop:
;     mov al, [rdi]
;     mov bl, [rsi]
;     cmp al, bl
;     jnz not_equal
;     test al,al
;     jz equal
;     inc rdi
;     inc rsi
;     jmp loop

; not_equal:
;     movzx eax, al
;     movzx ebx, bl
;     sub eax,ebx
;     ret
; equal:
;     xor eax,eax
;     ret
