#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//This function is used to figure out the ordering of the strings
//in qsort. You do not need to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}
//data is the pointer to lines(strings),count is numer of lines,
//sizeof(char *) is size of each line

int main(int argc, char ** argv) {
  // char * line = NULL;
  size_t sz = 0;
  size_t num = 0;
  char * ptr = NULL;
  char ** store = NULL;
  if (argc == 1) {
    FILE * f = stdin;
    if (f == NULL) {
      fprintf(stderr, "Could not open file");
      return EXIT_FAILURE;
    }
    // count = getline(&ptr, &sz, f);
    while (getline(&ptr, &sz, f) != -1) {
      store = realloc(store, sz * (num + 1));
      // for (ssize_t i = 0; i < count; i++) {
      //printf(" %c\n", ptr[i]);
      //  *(store[num]) = ptr[i];
      // (store[num])++;
      // }
      store[num] = ptr;
      //  printf("%s", store[num]);
      //store has size sz for each line,
      // free(&sz);
      //  free(ptr);
      num++;

      ptr = NULL;
      free(ptr);
      //  count = getline(&ptr, &sz, f);
    }
    free(ptr);
    sortData(store, num);
    for (size_t i = 0; i < num; i++) {
      printf("%s", store[i]);
      //   printf("%c", '\n');                                                                                                                                                                free(store[i]);
    }
    free(store);
    if (fclose(f) != 0) {
      fprintf(stderr, "Could not close file");
      return EXIT_FAILURE;
    }
  }

  //  ssize_t count = 0;
  if (argc > 1) {
    for (int i = 0; i < argc - 1; i++) {
      FILE * f = fopen(argv[i + 1], "r");
      if (f == NULL) {
        fprintf(stderr, "Could not open file");
        return EXIT_FAILURE;
      }
      // count = getline(&ptr, &sz, f);
      while (getline(&ptr, &sz, f) != -1) {
        store = realloc(store, sz * (num + 1));
        // for (ssize_t i = 0; i < count; i++) {
        //printf(" %c\n", ptr[i]);
        //  *(store[num]) = ptr[i];
        // (store[num])++;
        // }
        store[num] = ptr;
        //  printf("%s", store[num]);
        //store has size sz for each line,
        // free(&sz);
        //  free(ptr);
        num++;

        ptr = NULL;
        free(ptr);
        //  count = getline(&ptr, &sz, f);
      }
      free(ptr);
      sortData(store, num);
      for (size_t i = 0; i < num; i++) {
        printf("%s", store[i]);
        //   printf("%c", '\n');
        free(store[i]);
      }
      free(store);
      if (fclose(f) != 0) {
        fprintf(stderr, "Could not close file");
        return EXIT_FAILURE;
      }
      free(argv[i + 1]);
    }
    free(argv);
  }
  //WRITE YOUR CODE HERE!

  return EXIT_SUCCESS;
}
