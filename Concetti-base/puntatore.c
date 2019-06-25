#include <stdlib.h>
#include <stdio.h>

void print_es01(int a, int b, int c) {
  printf("\nA: %d | B: %d | C: %d", a, b, c);
}

void esempio_01() {
  int a = 0;
  int b = 1;
  int *c = &b;
  print_es01(a, b, *c);
}

int main() {

  esempio_01();

  return 0;
}
