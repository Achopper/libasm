global _ft_strcpy

;char*		ft_strcpy(char *dst, const char *src);

section .text
_ft_strcpy:
    push rbx
    xor rcx, rcx
    xor rax, rax
.loop:
    mov byte bl, [rsi + rcx]
    mov byte [rdi + rcx], bl
    cmp bl, 0x0
    je .ret
    inc rcx
    jmp .loop
.ret:
    mov byte [rdi + rcx], bl
    lea rax, [rdi]
    pop rbx
    ret

