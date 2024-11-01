#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

extern unsigned __int128 fibonacci(uint64_t n);
extern unsigned __int128 add();

void print_uint128(unsigned __int128 value)
{   
    add();
    uint64_t lower, upper;

    __asm__("mov %%rax, %0" : "=r" (lower));
    __asm__("mov %%rdx, %0" : "=r" (upper));
    printf("128-Bit-Ergebnis: 0x%016lx%016lx\n", upper, lower);
}

int main()
{

    // for (int i = 0; i <= 10; i++)
    // {
    //     printf("%d: ", i);
    //     //printf("%llu\n",fibonacci(i));
    //     //print_uint128(fibonacci(i));
    //     //printf("\n");
    // }

    print_uint128(12);


    return 0;
}