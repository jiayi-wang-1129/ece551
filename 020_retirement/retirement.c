#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

double bal_working(int startAge, double initial, retire_info working) {
  int start = startAge;
  int year = start / 12;
  int month = start - 12 * year;

  double balance = initial;
  int h = working.months;
  printf("Age %3d month %2d you have $%.2f\n", year, month, balance);
  for (int y = 0; y < h; y++) {
    balance += working.contribution + balance * (working.rate_of_return / 12);
    start++;
    year = start / 12;
    month = start - 12 * year;
    printf("Age %3d month %2d you have $%.2f\n", year, month, balance);
  }

  return balance;
}

void bal_retired(int startAge, double initial, retire_info working, retire_info retired) {
  int start = startAge + working.months;
  int year = start / 12;
  int month = start - 12 * year;
  double balance = bal_working(startAge, initial, working);
  int h = retired.months;
  for (int y = 0; y < h; y++) {
    balance += retired.contribution + balance * (retired.rate_of_return / 12);
    start++;
    year = start / 12;
    month = start - 12 * year;
    printf("Age %3d month %2d you have $%.2f\n", year, month, balance);
  }
}

void retirement(int startAge,         //in months
                double initial,       //initial savings in dollars
                retire_info working,  //info about working
                retire_info retired) {
  bal_working(startAge, initial, working);
  bal_retired(startAge, initial, working, retired);
}

int main(void) {
  retire_info working;
  working.contribution = 1000;
  working.months = 489;
  working.rate_of_return = 0.045;
  retire_info retired;
  retired.contribution = -4000;
  retired.months = 384;
  retired.rate_of_return = 0.01;
  int startAge = 327;
  double initial = 21345;
  retirement(startAge,
             initial,  //initial savings in dollars
             working,  //info about working
             retired);
  return 0;
}
