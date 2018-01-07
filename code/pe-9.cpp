#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  for (int c = 500; c >= 3; --c) {
    for (int b = c - 1; b >= 2; --b) {
      int a = 1000 - c - b;
      if (a * a + b * b == c * c) {
        printf ("%d * %d * %d = %d\n", a, b, c, a * b * c);
        exit(0);
      }
    }
  }

  return 0;
}

