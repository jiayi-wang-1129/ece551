#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void rotateMatrix(FILE * f) {
  int c;
  char str[12] = {0};
  //  char storing[10][10];
  // const char* matrix={0};//pointer to read each line
  //  const char ** ptr;//pointer to read inside of the line
  //  while ((c = fgetc(f)) != EOF) {
  //  int row = 0;
  //  char * line = fgets(str, 12, f);
  fprintf(stdout, "%s", fgets(str, 12, f));
  // for (int i = 0; i < 10; i++) {
  // storing[row][i] = *line;
  // line++;
  //  }
  // row++;
}
//  for (int w = 0; w < 10; w++) {
//  for (int y = 0; y < 11; y++) {
//    fprintf(stdout, "%c", storing[w][y]);
//  }
// }

// for (int n = 9; n >= 0; n--) {
//  for (int j = 0; j < 10; j++) {
//  fprintf(stdout, "%c", storing[j][n]);
//  }
//  fprintf(stdout, "\n");
// }

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "invalid number of input");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "Cannot open file");
    return EXIT_FAILURE;
  }
  rotateMatrix(f);
  if (fclose(f) != 0) {
    fprintf(stderr, "Cannot close file");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
