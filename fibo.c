#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

extern unsigned __int128 fibonacci(uint64_t n);

void uint128_to_string(unsigned __int128 num, char *str)
{
    int i = 0;
    char temp[40]; 
    if (num == 0)
    {
        str[i++] = '0';
    }
    else
    {
        while (num > 0)
        {
            temp[i++] = '0' + (num % 10); 
            num /= 10;
        }
        for (int j = 0; j < i; j++)
        {
            str[j] = temp[i - j - 1];
        }
    }
    str[i] = '\0'; 
}

void uint128_to_hex_string(unsigned __int128 num, char *str)
{
    uint64_t upper = (uint64_t)(num >> 64); 
    uint64_t lower = (uint64_t)num;         

    if (upper == 0)
    {
        sprintf(str, "0x%016llx", lower);
    }
    else
    {
        sprintf(str, "0x%016llx%016llx", upper, lower);
    }
}

int main()
{
    for (uint64_t i = 1; i <= 10; i++)
    {
        unsigned __int128 fib = fibonacci(i);

        char fib_str[40];     
        char fib_str_hex[35]; 
        
        uint128_to_hex_string(fib, fib_str_hex);

        printf("Fibonacci(%llu) = %s\n", i, fib_str_hex);
    }

    return 0;
}