#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);
void check(int * array, size_t n, size_t expected_ans) {
  if (maxSeq(array, n) == expected_ans) {
    printf("good");
  }
  else {
    printf("F = %zd, %zd\n ", expected_ans, maxSeq(array, n));
    exit(EXIT_FAILURE);
  }
}
int main(void) {
  int s1[3] = {2, 2, 2};
  int s2[3] = {2, 0, 2};
  int s3[4] = {0, 2, 1, 3};
  int s4[4] = {1, 2, 0};
  int s5[1] = {1};
  int s6[5] = {0, 1, 2, 3};
  int s7[6] = {0, 1, 0, 2, 0, 3};
  check(s1, 3, 1);
  check(s2, 3, 2);
  check(s3, 4, 2);

  check(s4, 4, 2);
  check(s6, 5, 4);
  check(s7, 6, 2);
  check(0, 0, 0);
  return 0;
}
