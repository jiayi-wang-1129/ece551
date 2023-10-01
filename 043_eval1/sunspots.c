#include "sunspots.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ss_monthly_t parseLine(char * line) {
  if (line == NULL) {
    fprintf(stderr, "input is NULL");
    exit(EXIT_FAILURE);
  }

  ss_monthly_t ans;
  ans.year = 0;
  ans.month = 0;
  ans.num = 0;

  const char * a = strchr(line, ',');
  a++;
  ans.num = atof(a);
  if (ans.num < 0) {
    fprintf(stderr, "input is negative for sunspots\n");
    exit(EXIT_FAILURE);
  }
  int size = strlen(line);
  char * year_c = &line[size - 5];
  strncpy(year_c, line, 4);
  ans.year = atoi(year_c);
  if (ans.year <= 0 || ans.year >= 9999) {
    fprintf(stderr, "Year input is invalid\n");
    exit(EXIT_FAILURE);
  }
  char * ptr = strchr(line, '-');
  ptr++;
  char * month_c = &line[size - 3];
  strncpy(month_c, ptr, 2);
  ans.month = atoi(month_c);
  if (ans.month <= 0 || ans.month >= 13) {
    fprintf(stderr, "Month input is invalid\n");
    exit(EXIT_FAILURE);
  }
  return ans;
}
//   if (line[4] != '-') {
//     fprintf(stderr, "Formating error:missing hyphen");
//     exit(EXIT_FAILURE);
//   }

//   if (line[7] != ',') {
//    fprintf(stderr, "Formating error:missing comma");
//    exit(EXIT_FAILURE);
//   }
//  if (!isdigit(line[0]) || !isdigit(line[1]) || !isdigit(line[2]) || !isdigit(line[3])) {
//   fprintf(stderr, "input year is not a number");
//   exit(EXIT_FAILURE);
//   }
//   else {
//    printf("%s %s %s %s", &line[0], &line[1], &line[2], &line[3]);
//   }
//   if (!isdigit(line[5]) || !isdigit(line[6])) {
//    fprintf(stderr, "input month is not a number");
//    exit(EXIT_FAILURE);
//   }
//   else {
//    printf("%s %s\n", &line[5], &line[6]);
//  }
//   if (atoi(&line[5]) >= 2 || (atoi(&line[5]) == 1 && atoi(&line[6]) > 2)) {
//    printf("%s %s\n", &line[5], &line[6]);
//    fprintf(stderr, "input is not valid for month");
//     exit(EXIT_FAILURE);
//   }
//   if (!isdigit(line[8])) {
//    fprintf(stderr, "input is not a floating number for sunspots-1");
//    exit(EXIT_FAILURE);
//   }
//   char year_c = line[0];
//   char month_c = line[5] + line[6];
//   printf("The month is %s:\n", &month_c);
//   const char * ptr = &line[8];
//   char num_c = *ptr;
//   ans.month = atoi(&month_c);
//   printf("The month is %d\n:", ans.month);
//   for (int i = 1; i < 4; i++) {
//    year_c += line[i];
//   }
//   printf("The year is %s:\n", &year_c);
//   ans.year = atoi(&year_c);
//   printf("The year is %d:\n", ans.year);

//   while (*ptr != '\0') {
//   ptr++;
//   int countdot = 0;
//   if (isdigit(*ptr)) {
//     num_c += *ptr;
//   }
//    if (*ptr == '.' && countdot == 0) {
//  countdot++;
//  num_c += *ptr;
//  }
//   }
//   ans.num = atof(&num_c);
//   printf("sunspot number is:%f\n", ans.num);
//  if (ans.num < 0) {
//  fprintf(stderr, "input is negative for sunspots\n");
// exit(EXIT_FAILURE);
//  }
//  return ans;
//}

void meanFilter(ss_monthly_t * data, size_t n, ss_monthly_t * mean, unsigned w) {
  // WRITE ME
}

double findLocalMax(ss_monthly_t * data, size_t n) {
  // WRITE ME
  return 0;
}

double calcSsPeriod(double * timeStamps, size_t n) {
  //WRITE ME
  return 0;
}
