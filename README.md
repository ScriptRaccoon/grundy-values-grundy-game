# Grundy values of Grundy's game

The Grundy values of [Grundy's game](https://en.wikipedia.org/wiki/Grundy's_game) can be computed recursively with the formula

$$g(n) = \mathrm{mex} \bigl\{ g(a) \oplus g(n-a) : 1 < a < n/2 \bigr\},$$
where $\mathrm{mex}$ denotes the minimal excluded value and $\oplus$ denotes the nim-sum (bitwise XOR).

This is the OEIS sequence [A002188](https://oeis.org/A002188).

This repository implements this sequence in a couple of programming languages. We also do performance tests to compare the speed of the languages.

```
C++ > Swift > Go > Rust > TypeScript > Python
```
