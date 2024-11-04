# Fibonacci 

The Fibonacci sequence is a series of numbers where each term is the sum of the two preceding ones, starting from 0 and 1. Mathematically, it's defined as $$F(n) = F(n-1) + F(n-2)$$, with initial terms $$F(0) = 0$$ and $$F(1) = 1$$. This sequence grows exponentially and appears in various fields, from mathematics to computer science and nature, often illustrating recursive patterns and efficient algorithms for problem-solving. Calculating large Fibonacci terms requires managing large numbers, as the values grow rapidly with each step.


# Pseudocode

```
fibonacci(nthNumber):
    nMinus2 = 0
    nMinus1 = 0
    n = 1

   for i from 1 to nthNumber - 1:
        nMinus2 = nMinus1
        nMinus1 = n
        n = nMinus2 + nMinus1

    return n
```

# Assembly implementation

The Fibonacci sequence grows exponentially, meaning that Fibonacci numbers increase in size very quickly. Calculating higher Fibonacci terms can rapidly exceed the capacity of standard integer sizes. In this implementation, 128-bit integers are used to handle the overflow risk associated with large Fibonacci values. By using 128-bit operations, the program can correctly calculate much larger Fibonacci terms without overflow, ensuring accurate results even for high input values that would otherwise exceed the limits of 64-bit integers

A total of six 64-bit registers are used, organized in pairs to represent `nMinus2`, `nMinus1`, and `n` as 128-bit values.
  
- Register assignments for each 128-bit value:
  - `nMinus2`:
    - Lower 64 bits: `r8`
    - Upper 64 bits: `r9`
  - `nMinus1`:
    - Lower 64 bits: `r10`
    - Upper 64 bits: `r11`
  - `n` (current Fibonacci term):
    - Lower 64 bits: `rax`
    - Upper 64 bits: `rdx`

This setup allows efficient handling of large Fibonacci values by pairing 64-bit registers to represent each term as a 128-bit number.


Details in implementation can be found in the comments of `fibo.S`.


# C Implementation

I just used Gary (ChatGPT) to generate this part as it wasn't the focus of the task. 

- `void uint128_to_string(unsigned __int128 num, char *str)` allows the 128-Bit integers to be printed as a string.
- `void uint128_to_hex_string(unsigned __int128 num, char *str)` allows the 128-Bit integers to be printed in hex as a string.
