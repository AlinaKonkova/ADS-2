// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  for (int i = 1; i <= n; i++) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  if (n <= 1)
    return 1;
  else
    return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  double num;
  num = pown(x, n) / fact(n);
  return num;
}

double expn(double x, uint16_t count) {
  double e = 0;
  int i = 0;
  while (i <= count) {
    e += calcItem(x, i);
    i++;
  }
  return e;
}

double sinn(double x, uint16_t count) {
  double sinc = 0;
  int i = 1;
  while (i <= count) {
    sinc += pown(-1, (i - 1)) * calcItem(x, (2 * i - 1));
    i++;
  }
  return sinc;
}

double cosn(double x, uint16_t count) {
  double cosc = 0;
  int i = 1;
  while (i <= count) {
    cosc += pown(-1, (i - 1)) * calcItem(x, (2 * i - 2));
    i++;
  }
  return cosc;
}
