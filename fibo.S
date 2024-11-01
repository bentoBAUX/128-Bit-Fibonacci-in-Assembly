.intel_syntax noprefix
.global fibonacci

.text

fibonacci:
	xor rdx, rdx
    cmp rdi, 0
    je .base0
    cmp rdi, 1
    je .base1

    xor r8, r8
    xor r9, r9

    xor r10, r10
    xor r11, r11

    mov eax, 1
    mov ecx, 1

.loop:
    cmp rcx, rdi
    je .end
    mov r8, r10
    mov r9, r11

    mov r10, rax
    mov r11, rdx

    add rax, r8
    adc rdx, r9

    jc .overflow

    inc rcx
    jmp .loop

.base0:
    xor rax, rax
    xor rdx, rdx
    ret

.base1:
    mov rax, 1
    ret

.overflow:
    mov rax, 0xFFFFFFFFFFFFFFFF
    mov rdx, 0xFFFFFFFFFFFFFFFF
    jmp .end

.end:
    ret




