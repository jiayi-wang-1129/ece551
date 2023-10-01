#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int find_max(int * array, size_t n) {
  int * ptr1 = array;
  size_t index = 0;
  for (size_t i = 1; i < n; i++) {
    if (array[i] > *ptr1) {
      ptr1 = &array[i];
      index = i;
    }
  }
  return index;
}
void find_e(FILE * f) {
  int c;
  int ptr[26];
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      ptr[c - 'a']++;
    }
  }
  int e_ = find_max(ptr, 26);
  int key;
  if (e_ >= 4) {
    key = e_ - 4;
  }
  else {
    key = e_ + 22;
  }
  fprintf(stderr, "%d\n", key);
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: inputFileName\n");
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  find_e(f);
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
