/*
https://stackoverflow.com/questions/145838/benefits-of-inline-functions-in-c

In archaic C and C++, inline is like register: a suggestion (nothing more than a suggestion) to the compiler about a possible optimization.

In modern C++, inline tells the linker that, if multiple definitions (not declarations) are found in different translation units, they are all the same, and the linker can freely keep one and discard all the other ones.

inline is mandatory if a function (no matter how complex or "linear") is defined in a header file, to allow multiple sources to include it without getting a "multiple definition" error by the linker.

Member functions defined inside a class are "inline" by default, as are template functions (in contrast to global functions).
*/

/*************************************
//fileA.h
inline void afunc()
{ std::cout << "this is afunc" << std::endl; }

//file1.cpp
#include "fileA.h"
void acall()
{ afunc(); }

//main.cpp
#include "fileA.h"
void acall();

int test()
{
   afunc();
   acall();
}
*************************************/

/*
//output
this is afunc
this is afunc
Note the inclusion of fileA.h into two .cpp files, resulting in two instances of afunc(). The linker will discard one of them. If no inline is specified, the linker will complain.
*/