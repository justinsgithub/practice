#include <math.h>
#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rect {
  struct point pt1;
  struct point pt2;
};

struct point pt = {100, 200};

struct rect screen;

int main() {
  double dist, sqrt(double);
  dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y); /* compute the distance from the origin (0,0) to pt */

  printf("%d, %d\n", pt.x, pt.y);
  printf("%f\n", dist);
  return 0;
}
