#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

extern unsigned __int128 fibonacci(uint64_t n);

void uint128_to_string(unsigned __int128 num, char *str)
{
    int i = 0;
    char temp[40]; // 128-Bit-Zahl passt sicher in 39 Dezimalstellen
    if (num == 0)
    {
        str[i++] = '0';
    }
    else
    {
        while (num > 0)
        {
            temp[i++] = '0' + (num % 10); // Ziffer extrahieren
            num /= 10;
        }
        // Reihenfolge umkehren
        for (int j = 0; j < i; j++)
        {
            str[j] = temp[i - j - 1];
        }
    }
    str[i] = '\0'; // Nullterminierung des Strings
}

void uint128_to_hex_string(unsigned __int128 num, char *str)
{
    uint64_t upper = (uint64_t)(num >> 64); // Oberes 64-Bit
    uint64_t lower = (uint64_t)num;         // Unteres 64-Bit

    if (upper == 0)
    {
        // Nur unteres 64-Bit benötigt
        sprintf(str, "0x%016llx", lower);
    }
    else
    {
        // Volle 128-Bit-Zahl als Hexadezimal-String
        sprintf(str, "0x%016llx%016llx", upper, lower);
    }
}

int main()
{
    // Fibonacci-Zahlen von 1 bis 100 berechnen und ausgeben
    for (uint64_t i = 1; i <= 200; i++)
    {
        unsigned __int128 fib = fibonacci(i);

        // Puffer für die Ausgabe
        char fib_str[40];     // 128-Bit passt in 39 Stellen plus Nullterminierung
        char fib_str_hex[35]; 
        //uint128_to_string(fib, fib_str);
        uint128_to_hex_string(fib, fib_str_hex);

        // Ausgabe der Fibonacci-Zahl
        printf("Fibonacci(%llu) = %s\n", i, fib_str_hex);
    }

    return 0;
}