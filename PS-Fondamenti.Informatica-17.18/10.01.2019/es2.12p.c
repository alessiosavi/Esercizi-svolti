#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../c-library/log.h"
#include "../c-library/log.c"

/*
 * NOTE: compile with
 * cc es2.12p.c -lm
 * */

/* Date due liste A e B, scrivere:
 *
 * - Metodo che restituisce la media della
 *   lista avente minima deviazione standard
 *
 * - Funziona che calcoli la media della lista in input
 *   e crei una nuova lista con il valore diminuito della media */

void print_array(int *array, int array_lenght);

int *init_array(int size);

double std_dev(int *array, int lenght);

float _std(int *array, int lenght);

int *lowerize_by_std_value(const int *array, int size, int std_value);

int main() {
  int array_lenght;
  int *array_A, *array_B, *array_lowerized;
  log_debug("main | START!");
  log_debug("main | Insert lenght of array: ");
  scanf("%d", &array_lenght);
  log_debug("main | Arraylenght -> %d", array_lenght);

  srand(time(0));
  array_A = init_array(array_lenght);
  array_B = init_array(array_lenght);

  double std_dev_A = std_dev(array_A, array_lenght);
  double std_dev_B = std_dev(array_B, array_lenght);

  int *min_std_array = NULL;
  float min_std_val = 0;
  if (std_dev_A < std_dev_B) {
    // Save the data that we need for continue the flow
    min_std_array = array_A;
    min_std_val = std_dev_A;
    log_debug("La lista A ha std_deviation più bassa [%f] della lista B [%f]",
              std_dev_A, std_dev_B);
    log_debug("La media della lista A è --> %f", _std(array_A, array_lenght));
  } else {
    min_std_array = array_B;
    min_std_val = std_dev_B;
    log_debug("La lista B ha std_deviation più bassa [%f] della lista A [%f]",
              std_dev_B, std_dev_A);
    log_debug("La media della lista B è --> %f", _std(array_B, array_lenght));
  }
  // We can free the data, we have found what we need!
  free(array_A);
  free(array_B);

  print_array(min_std_array, array_lenght);
  log_debug("Generando array diminuito della media ...");
  array_lowerized =
      lowerize_by_std_value(min_std_array, array_lenght, min_std_val);

  print_array(array_lowerized, array_lenght);
  free(array_lowerized);
  return 0;
}

// Calcola media di un array
float _std(int *array, int lenght) {
  int i = 0;
  int total = 0;
  for (; i < lenght; i++) {
    total += array[i];
  }
  return (float)total / (float)lenght;
}

/*
 * 1) (x[i] - std[x])
 * 2) (Step 1)^2
 * 3) total += Step 2 (iterate)
 * 4) Step 3 / N
 * 5) sqrt(step 4)
 */

// Calcola deviazione standard di un array
double std_dev(int *array, int lenght) {
  float std = _std(array, lenght);
  int i;
  float step3 = 0; /* total ...*/
  for (i = 0; i < lenght; i++) {
    float step1 = array[i] - std;
    float step2 = step1 * step1; /* step1^2*/
    step3 += step2;
  }
  float step4 = step3 / (float)lenght;

  return sqrt(step4);
}

int *init_array(int size) {
  int *array = (int *)malloc(size * sizeof(int));
  // Comment this if you want same value @runtime [seed]
  int i;
  for (i = 0; i < size; i++) {
    /* random int between 1 and 20 */
    array[i] = (rand() % 19) + 1;
  }
  log_debug("Array initializzato!");
  print_array(array, size);
  return array;
}

void print_array(int *array, int array_lenght) {
  if (array_lenght > 50) {
    printf("\nInput > 50char censured!");
    return;
  }
  int i = 0;
  for (i = 0; i < array_lenght; i++) {
    /* random int between 0 and 19 */
    printf("%d ", array[i]);
  }
  printf("\n");
}

// lowerize every item of the array by the std_value
int *lowerize_by_std_value(const int *array, int size, int std_value) {
  int *lowerized = (int *)malloc(size * sizeof(int));
  int i = 0;
  for (; i < size; i++) {
    lowerized[i] = array[i] - std_value;
  }
  return lowerized;
}
