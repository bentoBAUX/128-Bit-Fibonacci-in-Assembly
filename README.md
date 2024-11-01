## Pseudocode

```
Function fibonacciLoop(nthNumber):
    nMinus2 = 0
    nMinus1 = 0
    n = 1

    For i from 1 to nthNumber - 1:
        nMinus2 = nMinus1
        nMinus1 = n
        Set n = nMinus2 + nMinus1

    Return n
```

## Assembly implementation

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
