global _ft_read
extern ___error

;ssize_t		ft_read(int fildes, void *buf, size_t nbyte);

section .text
_ft_read:
        mov rax, 0x02000003
        syscall
        jc .ret_error
        ret
.ret_error:
        push rax
        call ___error
        pop rcx
        mov [rax], rcx
        mov rax, -1
        ret