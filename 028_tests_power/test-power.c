#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);
void run_check(unsigned x, unsigned y, unsigned expected_ans) {
  if (power(x, y) == expected_ans) {
    printf("good");
    exit(EXIT_SUCCESS);
  }
  else {
    printf("Fail");
    exit(EXIT_FAILURE);
  }
}
int main(void) {
  run_check(2, 2, 4);
  run_check(0, 0, 1);
  return 0;
}
