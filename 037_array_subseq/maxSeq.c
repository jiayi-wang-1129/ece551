#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n) {
  size_t count = 0;
  int array1[n];
  int * q = &array1[1];
  int * p = &array1[1];
  for (size_t i = 1; i < n; i++) {
    if (array[i] > array[i - 1]) {
      count++;
      q++;
      *q = count;
      if (*q > *p) {
        p = q;
      }
    }
    else {
      count = 0;
    }
  }
  if ((*p == 0) & (n >= 1)) {
    return 1;
  }
  if ((count == 0) & (n < 1)) {
    return 0;
  }
  else {
    return *p + 1;
  }
}
