.intel_syntax noprefix
.global fibonacci

.text

fibonacci:
    xor rdx, rdx
    mov rax, rdi

    cmp rdi, 2
    jb .end

    mov eax, 1
    mov r8d, 0
    mov r9d, 0

    mov r10d, 0
    mov r11d, 0
	
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

    add rcx, 1
    jmp .loop


.overflow:
    mov rax, 0xFFFFFFFFFFFFFFFF
    mov rdx, 0xFFFFFFFFFFFFFFFF
    jmp .end

.end:
    ret