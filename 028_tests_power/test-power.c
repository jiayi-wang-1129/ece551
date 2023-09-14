#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);
void run_check(unsigned x, unsigned y, unsigned expected_ans) {
  if (power(x, y) == expected_ans) {
    printf("good");
  }
  else {
    printf("F %d\n", power(x, y));
    exit(EXIT_FAILURE);
  }
}
int main(void) {
  run_check(2, 2, 4);
  run_check(200, 4, 1600000000);
  run_check(0, 0, 1);
  return 0;
}
