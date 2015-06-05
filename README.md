# ComputorV1_Cplusplus
With a brief intro in PhP to OOP, this is my first project ever in object-oriented design and C++.
I have never coded in C++ before.

Goal of the project: solve until the 2nd polynomial degree equations, and find their zeros.
Input string like this: - 1.23... * X^4... + ... = ... [with no spaces]

In Regex: (((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]])+))?)?\\*X(\\^((\\+|-)?[[:digit:]]+))?

"(((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?)))" --> real number
"((\\+|-)?[[:digit:]]+)" --> integer number