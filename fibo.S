.intel_syntax noprefix
.global fibonacci

.text

// r8 & r9 for nMinus2
// r10 & r11 for nMinus1
// rax & rdx for n

fibonacci:
    xor rdx, rdx
    mov rax, rdi        

    cmp rdi, 2 // Taking care of case 0 and 1
    jb .end

    // n = 1
    mov eax, 1

    // nMinus2 = 0
    xor r8, r8
    xor r8, r8

    // nMinus1 = 0
    xor r10, r10
    xor r11, r11
	
    mov ecx, 1

.loop:
    cmp rcx, rdi
    je .end
    
    // nMinus2 = nMinus1
    mov r8, r10
    mov r9, r11

    // nMinus1 = n
    mov r10, rax
    mov r11, rdx

    // n = nMinus2 + nMinus1
    add rax, r8 // This creates a carry flag which is caught by adc in the next line
    adc rdx, r9 // adds the upper halves of nMinus2 and nMinus1 + carry

    jc .overflow // Takes care of overflow after 128 bits.

    inc rcx
    jmp .loop


.overflow:
    mov rax, 0xFFFFFFFFFFFFFFFF
    mov rdx, 0xFFFFFFFFFFFFFFFF
    jmp .end

.end:
    ret