#include "chaptertwo.h"
#include <float.h>
#include <limits.h>
#include <stdio.h>

void type_ranges() {
  // Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables, both signed and
  // unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute
  // them: determine the ranges of the various floating-point types.

  printf("signed char range = %d - %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("unsigned char range = 0 - %d\n", UCHAR_MAX);
  // printf("%d\n", UCHAR_MAX);
  // printf("%d\n", SHRT_MIN);
  // printf("%d\n", SHRT_MAX);
  // printf("%d\n", USHRT_MAX);
  // printf("%d\n", INT_MIN);
  // printf("%d\n", INT_MAX);
  // printf("%d\n", UINT_MAX);
  // printf("%d\n", LONG_MIN);
  // printf("%d\n", LONG_MAX);
  // printf("%d\n", ULONG_MAX);
  // printf("%d\n", CHAR_BIT);
  // printf("%d\n", CHAR_MIN);
  // printf("%d\n", CHAR_MAX);
}
