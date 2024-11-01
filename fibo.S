.intel_syntax noprefix
.global fibonacci

.text
fibonacci:
	xor rdx, rdx

    cmp rdi, 0
    je .base0
    cmp rdi, 1
    je .base1

    xor r8, r8  // n-2
    xor r9, r9  // n-1
    mov eax, 1
    
    mov ecx, 1

.loop:
    cmp rcx, rdi
    je .end
    mov r8, r9  //prevprev = prev
    mov r9, rax //prev = current
    add rax, r8 //current = prevprev + prev
                //handle overflow
    inc rcx
    jmp .loop


.base0:
    xor rax, rax
    xor rdx, rdx
    ret

.base1:
    mov rax, 1
    ret

.end:
    ret




