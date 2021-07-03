#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types. */
main()
{
    /* UNSIGNED TYPES */
    printf("\n\tUNSIGNED TYPES\n");
    printf("UNSIGNED CHAR:  %d      %d\n", 0, UCHAR_MAX);
    printf("UNSIGNED SHORT: %d      %d\n", 0, USHRT_MAX);
    printf("UNSIGNED INT:   %d      %d\n", 0, UINT_MAX);
    printf("UNSIGNED LONG:  %d      %d\n", 0, ULONG_MAX);
    
    /* SIGNED TYPES */
    printf("\n\tSIGNED TYPES\n");
    printf("SIGNED CHAR:  %d     %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("SIGNED SHORT: %d     %d\n", SHRT_MIN, SHRT_MAX);
    printf("SIGNED INT:   %d     %d\n", INT_MIN, INT_MAX);
    printf("SIGNED LONG:  %d     %d\n\n", LONG_MIN, LONG_MAX);
    
    /* FLOAT & DOUBLE TYPES */
    printf("FLOAT:            %d     %d\n", FLT_MIN, FLT_MAX);
    printf("FLOAT EXPONENTS:  %d     %d\n", FLT_MIN_EXP, FLT_MAX_EXP);
    printf("DOUBLE:           %d     %d\n", DBL_MIN, DBL_MAX);
    printf("DOUBLE EXPONENTS: %d     %d\n", DBL_MIN_EXP, DBL_MAX_EXP);
}
