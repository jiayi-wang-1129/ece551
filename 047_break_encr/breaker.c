#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int find_max(int * array) {
  int index = 0;
  int max = array[0];
  for (int i = 1; i < 26; i++) {
    if (array[i] > max) {
      max = array[i];
      index = i;
    }
  }
  return index;
}

void breaker(FILE * f) {
  int c;
  int ptr[26];
  for (int i = 0; i < 26; i++) {
    ptr[i] = 0;
  }
  while ((c = fgetc(f)) != EOF) {
    if ((isalpha(c))) {
      c = tolower(c);
      ptr[c - 'a']++;
    }
  }
  int max = find_max(ptr);
  int key;
  if (max >= 4) {
    key = max - 4;
  }
  else {
    key = 22 + max;
  }

  printf("%d\n", key);
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  breaker(f);

  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
