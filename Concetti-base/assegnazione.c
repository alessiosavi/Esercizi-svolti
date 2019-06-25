#include <stdio.h>
#include <stdlib.h>

void SommaP(int A, int B, int *C) { *C = A + B; }

main() {
  int a, b = 5, c = 2;
  SommaP(b, c, &a);
  printf("A che valore punta a? %d", a);
}
