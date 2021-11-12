global _ft_strlen

;size_t		ft_strlen(const char *s);

section .text
_ft_strlen:
        xor rcx,rcx
.loop:
        cmp byte [rdi + rcx], 0
        je .ret
        inc rcx
        jmp .loop
.ret:
        mov rax, rcx
        ret




