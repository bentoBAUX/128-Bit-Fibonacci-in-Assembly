.intel_syntax noprefix
.global add

.text

add:
    mov r8, 0xFFFFFFFFFFFFFFFF
    mov r9, 0x0000000000000000

    mov r10, 0x000000000000002
    mov r11, 0x000000000000000

    add r8, r10
    adc r9, r11

    mov rax, r8
    mov rdx, r9

    ret