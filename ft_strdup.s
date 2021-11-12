global _ft_strdup

extern _ft_strlen
extern _ft_strcpy
extern _malloc

;char*     strdup(const char *s1);

section .text
_ft_strdup:
        mov rsi, rdi
        call _ft_strlen
        inc rax             ;+1 byte for \0
        mov rdi, rax        ;mov strlen res in malloc 1st arg
        push rsi            ;push *s1 on stack
        call _malloc
        pop rsi
        cmp rax, 0x0        ;test malloc err
        je .err
        mov rdi, rax
        call _ft_strcpy
.err:   ret

