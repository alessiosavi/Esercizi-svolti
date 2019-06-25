#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
 * Dato un array statico, scrivere una funzione che:
 *  - Stampa a video gli elementi pari;
 *  - Conti e ritorni il numero degli elementi dispari;
 * */

/* ============ FILE.H ============= */
/* Delegated to initialize a new array*/
int *crea_array(int size);

/* Iterate the array and print the pair number  */
void print_pari(int *array, int size);

/* Iterate the array and return the count of not pair number  */
int trova_dispari(int *array);

/* Stampa l'array */
void print_array(int *array, int size);

/* Return number of dispari */
int count_dispari(int *array, int size);
/* ========== FILE.C ==============*/

int main() {
  srand(time(0));

  int M = rand() % 50 + 1;
  // Init random number seed
  printf("\nUsing %d as array size ...\n", M);

  int *array = crea_array(M);
  print_array(array, M);
  print_pari(array, M);
  // print_dispari(array,M);
  printf("\nNumber of dispari: %d", count_dispari(array, M));
}

void print_pari(int *array, int size) {
  int i = 0;
  for (; i < size; i++) {
    if (array[i] % 2 == 0) {
      printf("\nprint_pari | Indice [%d] è pari --> %d", i, array[i]);
    }
  }
}

int count_dispari(int *array, int size) {
  int i = 0;
  int count = 0;
  for (; i < size; i++) {
    if (array[i] % 2 != 0) {
      count += 1;
    }
  }
  return count;
}

int *crea_array(int size) {
  int *array = malloc(size * sizeof(int));
  int i = 0;
  for (; i < size; i++)
    array[i] = rand();
  return array;
}

void print_array(int *array, int size) {
  printf("\nprint_array | START!\n");
  int i = 0;
  while (i < size) {
    printf("%d | ", array[i]);
    ++i;
  }
  printf("\nprint_array | STOP!\n");
}
