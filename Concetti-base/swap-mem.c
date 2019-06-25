#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_array(int *array, int size) {
  int i = 0;
  while (i < size) {
    array[i] = i;
    ++i;
  }
}

void print(int *array, int size) {
  int i = 0;
  while (i < size) {
    printf("%d ", array[i++]);
  }
}

void test01() {

  printf("\n========= TEST 1 =======\n");
  int max = 10;

  int *a = malloc(max * sizeof(int));
  int *b = calloc((max + 1), (max + 1) * sizeof(int));
  int i = 0;
  for (; i < max; i++) {
    a[i] = i;
  }
  print(a, max);

  memcpy(b, a, max * sizeof(int));

  printf("\n");
  print(b, max + 1);

  free(a);
  free(b);
  printf("\n========= TEST 1 =======\n");
}

/* Copy half array in another*/
void test02() {
  printf("\n========= TEST 2 =======\n");
  int size = 5;

  int *a = malloc((size * 2) * sizeof(int));
  int *b = calloc(size, size * sizeof(int));
  init_array(a, size * 2);
  /* Copy half address */
  memcpy(b, &a[size], size * sizeof(int));
  print(b, size);
  free(a);
  free(b);
  printf("\n========= TEST 2 =======\n");
}

int main() {
  test01();
  test02();
  return 0;
}
