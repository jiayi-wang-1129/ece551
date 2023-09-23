#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n) {
  size_t count = 0;
  int array1[n];
  array = &array[0];
  for (size_t i = 1; i < n; i++) {
    if (array[i] > array[i - 1]) {
      count++;
      array1[i] = count;
      array = &array1[i];
    }
    else {
      count = 0;
    }
  }
  if ((count == 0) & (n > 1)) {
    return 1;
  }
  if ((count == 0) & (n <= 1)) {
    return 0;
  }
  else {
    return *array + 1;
  }
}
