global _ft_strcmp

;int			ft_strcmp(const char *s1, const char *s2);

section .text
_ft_strcmp:
     push rbx
     xor rbx,rbx
     xor rcx,rcx
     xor rax,rax
.loop:
    mov byte bl, [rsi + rcx]
    mov byte al, [rdi + rcx]
    cmp al, bl
    jne .ret
    cmp al, 0x0
    je .ret
    cmp bl, 0x0
    je .ret
    inc rcx
    jmp .loop
.ret:
    sub rax, rbx
    pop rbx
    ret