//#include "kv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _kvpair_t {
  char * key;
  char * value;
};
typedef struct _kvpair_t kvpair_t;

struct _kvarray_t {
  kvpair_t ** array;
  size_t length;
};

typedef struct _kvarray_t kvarray_t;
kvarray_t * readKVs(const char * fname) {
  kvarray_t * ptr = malloc(sizeof(kvarray_t));
  ptr->array = NULL;
  ptr->length = 0;
  size_t sz = 0;
  char ** p = NULL;
  FILE * f = fopen(fname, "r");
  if (f == NULL) {
    fprintf(stderr, " File has nothing");
    exit(EXIT_FAILURE);
  }
  while (getline(p, &sz, f) != -1) {
  }
  if (fclose(f) != 0) {
    fprintf(stderr, "Failed to close the file");
    exit(EXIT_FAILURE);
  }

  return

  //WRITE ME
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
}
