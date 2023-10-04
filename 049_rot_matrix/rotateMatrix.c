#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void rotateMatrix(FILE * f) {
  //

  char line[12] = {0};
  char storing[10][10];
  //  char output[10][10];
  // const char* matrix={0};//pointer to read each line
  int row = 0;
  //  const char ** ptr;//pointer to read inside of the line
  while (fgets(line, 12, f) != NULL) {
    //  char * line = fgets(str, 12, f);
    // fprintf(stdout, "%s", fgets(str, 12, f));
    //  fgets(str, 12, f);

    if (row == 10) {
      fprintf(stderr, "Input has more than 10 lines");
      exit(EXIT_FAILURE);
    }
    if (strchr(line, '\n') == NULL) {
      fprintf(stderr, "there is a line missing new space");
      exit(EXIT_FAILURE);
    }
    if (line[10] != '\n') {
      fprintf(stderr, "input does not have right format");
      exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; i++) {
      storing[row][i] = line[i];
    }
    row++;
  }

  //1, more than 10 lines 2.each line more than 10 string before /n, or has stuff after string
  //  for (int w = 0; w < 10; w++) {
  //  for (int y = 0; y < 10; y++) {
  //   fprintf(stdout, "%c", storing[w][y]);
  //  }
  // fprintf(stdout, "\n");
  // }
  //}

  for (int n = 0; n < 10; n++) {
    for (int j = 9; j >= 0; j--) {
      fprintf(stdout, "%c", storing[j][n]);
      //  output[9 - n][j] = storing[j][n];
    }
    fprintf(stdout, "\n");
  }
}

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
