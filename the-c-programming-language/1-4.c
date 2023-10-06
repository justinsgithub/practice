#include <stdio.h>

int main(){
  float fahr, celsius;
  float times_by;
  int lower, upper, step;

  times_by = 9.0/5.0;
  lower = 0;
  upper = 300;
  step = 10;
  celsius = lower;

  printf("Celsius-Fahrenheit table\n");
  while (celsius <= upper) {
    fahr = celsius * times_by + 32;
    printf("%3.0f %6.1f\n", celsius, fahr );
    celsius = celsius + step;
  }
}
