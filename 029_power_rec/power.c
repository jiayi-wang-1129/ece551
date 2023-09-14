#include <stdio.h>
#include <stdlib.h>

unsigned value = 0;
unsigned power(unsigned x, unsigned y) {
  if (x == 0) {
    if (y == 0) {
      return 1;
    }
    return 0;
  }
  if (y > 1) {
    y--;
    value = x * power(x, y);
    return value;
  }
  else {
    return x;
  }
}
