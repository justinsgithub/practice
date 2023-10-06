#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 10

int main() {
  float fahr, celsius;
  float times_by;

  times_by = 9.0 / 5.0;
  celsius = UPPER;

  printf("Celsius-Fahrenheit table\n");
  while (celsius >= LOWER) {
    fahr = celsius * times_by + 32;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius - STEP;
  }
}
