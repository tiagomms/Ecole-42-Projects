# ComputorV1_Cplusplus

**ComputorV1 is a calculator of polynomials in the second or less degree.**
For the calculations, it is used the quadratic formula.

Polynomials of higher degree are not calculated.
This is all done in the terminal, after making the Makefile.

Try out (must always use capital X):

```
make // to create the executable ./computor
./computor "X^2 -2*X + 1 = 0"
./computor "X -2*X^1 + 1 = 25*X^0"
./computor "3*X^2 -2*X^1 + 1 = 25*X^0"
./computor "X^2 -2*X^3 + 1 = 0"
./computor "X^2 -2*X^3 + 1 = -2*X^3"
./computor "25 = 25"
./computor "23 = 21"
(...)
```

When it is possible, the executable returns a fraction (not necessarily irreductible).

This was my first project in object-oriented programming and C++.
