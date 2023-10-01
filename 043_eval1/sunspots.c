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
  //Parse nums
  const char * a = strchr(line, ',');
  a++;
  ans.num = atof(a);
  if (ans.num < 0) {
    fprintf(stderr, "input is negative for sunspots\n");
    exit(EXIT_FAILURE);
  }
  //Parse year
  int size = strlen(line);
  char * year_c = &line[size - 5];
  strncpy(year_c, line, 4);
  ans.year = atoi(year_c);
  if (ans.year <= 0 || ans.year >= 9999) {
    fprintf(stderr, "Year input is invalid\n");
    exit(EXIT_FAILURE);
  }
  //Parse months
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
  size_t h_w = w / 2;
  //Standarlize array mean;
  for (size_t r = 0; r < n; r++) {
    mean[r].year = data[r].year;
    mean[r].month = data[r].month;
    mean[r].num = 0;
  }
  //when computing average,for loop below could include w/2 elements for index both larger and smaller than i;
  for (size_t i = h_w; i < n - h_w; i++) {
    for (size_t j = i - h_w; j <= i + h_w; j++) {
      mean[i].num += data[j].num;
    }
    mean[i].num = mean[i].num / w;
  }
  //Could include w/2 elements for index larger than m
  for (size_t m = 0; m < h_w; m++) {
    for (size_t n1 = 0; n1 <= m; n1++) {
      mean[m].num += data[n1].num;
    }
    for (size_t n2 = m + 1; n2 <= m + h_w; n2++) {
      mean[m].num += data[n2].num;
    }

    mean[m].num = mean[m].num / (m + 1 + h_w);
  }
  //Could include w/2 elements for index smaller than p
  for (size_t p = n - 1; p > n - 1 - h_w; p--) {
    for (size_t q1 = n - 1; q1 >= p; q1--) {
      mean[p].num += data[q1].num;
    }
    for (size_t q2 = p - 1; q2 >= p - h_w; q2--) {
      mean[p].num += data[q2].num;
    }
    mean[p].num = mean[p].num / (h_w + n - p);
  }
}

double findLocalMax(ss_monthly_t * data, size_t n) {
  if (n == 0) {
    fprintf(stderr, "Array has size 0, error");
    exit(EXIT_FAILURE);
  }
  double time_s = 0;
  size_t index = 0;
  const double * ptr = &data[0].num;
  const double * store = ptr;
  for (size_t i = 1; i < n; i++) {
    if (data[i - 1].num < data[i].num) {
      ptr = &data[i].num;
      //ptr captures increasing interval;
    }
    else {
      if (*ptr > *store) {
        store = ptr;
        index = i - 1;
      }
    }
  }
  if (*store < *ptr) {
    //in above case, local max has never been reached, the value was strictly increasing, the largest value is at end.
    time_s = data[n - 1].year + data[n - 1].month / 12.0;
  }
  if (ptr == &data[0].num) {
    //in above case,if ptr never moves, means the value only decreases(also store == ptr);the largest is at beginning.
    time_s = data[0].year + data[0].month / 12.0;
  }
  else {
    //else includes: *store =*ptr and ptr has moved;or store points to larger value than ptr does. We use "index" both cases.
    time_s = data[index].year + data[index].month / 12.0;
  }

  return time_s;
}

double calcSsPeriod(double * timeStamps, size_t n) {
  if (n < 2) {
    fprintf(stderr, "input size is less than 2");
    exit(EXIT_FAILURE);
  }
  if (n == 2) {
    return timeStamps[1] - timeStamps[0];
  }

  double result = 0;
  for (size_t i = 1; i < n; i++) {
    result += timeStamps[i] - timeStamps[i - 1];
    if (timeStamps[i] - timeStamps[i - 1] <= 0) {
      fprintf(stderr, "input of timeStamps is not an increasing array, error");
      exit(EXIT_FAILURE);
    }
  }
  //Instead of the for loop above, one could also obtain the sum by directly computing timeStamps[n - 1] - timeStamps[0]);
  //However, the for loop helps us checking if there is invalid input(negative difference of time stamps.

  return result / (n - 1);
}
