/*
 * Date due matrici diagonali quadrate (chiamate 'A' e 'B') scrivere i seguenti
 *metodi:
 * - Prodotto tra matrici --> A * B --> C
 * - Assegnamento della nuova 'matrice prodotto' ad A ( A --> C)
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include "datastructures.h"
#include "../c-library/log.h"
#include "../c-library/log.c"

long **init_matrix(int righe, int colonne) {
  int i;
  long **matrix = (long **)malloc(righe * sizeof(long *));
  for (i = 0; i < righe; i++)
    matrix[i] = (long *)malloc(colonne * sizeof(long));
  return matrix;
}

void populate_matrix(struct matrice *matrix, int n_righe, int n_colonne,
                     char *name) {
  matrix->n_righe = n_righe;
  matrix->n_colonne = n_colonne;
  matrix->matrix = init_matrix(matrix->n_righe, matrix->n_colonne);
  matrix->nome = name;
  int i;
  int j;
  int tmp_value = 1;
  printf("Creazione matrice di dimensione [%d]x[%d] ...", n_righe, n_colonne);
  for (i = 0; i < matrix->n_righe; i++) {
    for (j = 0; j < matrix->n_colonne; j++) {
      printf("\nInserisci elemento riga [%d] colonna [%d] --> ", i, j);
      scanf("%d", &tmp_value);
      matrix->matrix[i][j] = tmp_value;
    }
  }
}

struct matrice *populate_empty_matrix(int n_righe, int n_colonne, char *name) {
  struct matrice *matrix = (struct matrice *)malloc(sizeof(struct matrice));
  matrix->n_righe = n_righe;
  matrix->n_colonne = n_colonne;
  matrix->matrix = init_matrix(matrix->n_righe, matrix->n_colonne);
  matrix->nome = name;
  return matrix;
}

// Verify if product function can be applied (1 -> OK | -1 -> ERROR)
int validate_dimension(struct matrice *A, struct matrice *B) {
  if (A->n_colonne == B->n_righe) {
    return 1;
  }
  return -1;
}

struct matrice *calculate_product(struct matrice *matrix_A,
                                  struct matrice *matrix_B) {

  /* Puoi calcolare il prodotto solo se il numero delle colonne della prima
   * matrice
   * è uguale al numero di righe della seconda matrice */

  if (!(validate_dimension(matrix_A, matrix_B) == 1)) {
    printf("Dimensioni errate! | Puoi calcolare il prodotto solo se il "
           "numero delle colonne della prima matrice sia uguale al numero di "
           "righe della seconda matrice");
    return NULL;
  }
  // FIXME: Remember to free() | Create a new matrix with the compliant
  // dimension
  struct matrice *matrix_C =
      populate_empty_matrix(matrix_A->n_colonne, matrix_B->n_righe, "PRODUCT");
  int i, j, k;
  int M = matrix_A->n_righe;
  int P = matrix_B->n_colonne;
  int N = matrix_A->n_colonne; // OR matrix_B->n_righe;

  // Calculate product
  for (i = 0; i < M; i++)
    for (j = 0; j < P; j++) {
      matrix_C->matrix[i][j] = 0;
      for (k = 0; k < N; k++)
        matrix_C->matrix[i][j] =
            matrix_C->matrix[i][j] +
            matrix_A->matrix[i][k] * matrix_B->matrix[k][j];
    }
  return matrix_C;
}

void pretty_print(struct matrice *matrix) {
  printf("\nMatrix [%s]\n", matrix->nome);
  int row, columns;
  for (row = 0; row < matrix->n_righe; row++) {
    for (columns = 0; columns < matrix->n_colonne; columns++) {
      printf("%ld     ", matrix->matrix[row][columns]);
    }
    printf("\n");
  }
}

/* Initialize a new empty linear list */
struct linear_list *init_linear_list() {
  return (struct linear_list *)malloc(sizeof(struct linear_list));
}

struct linear_list *add_node(struct linear_list *list, double data) {
  if (list == NULL) {
    log_debug("add_node | some input data is NULL!");
    return NULL;
  }
  struct linear_list *node = init_linear_list();
  node->data = data;
  list->next = node;
  node->previous = list;
  return node;
}

void remove_node(struct linear_list *list, struct linear_list *node) {
  int found = -1;
  struct linear_list *tmp_node = NULL;
  tmp_node = list;
  while (found == -1) {
    if (tmp_node->data == node->data) {
      found = 0; /* FOUND! */
      // link the previous node with the next :D
      tmp_node->previous = tmp_node->next;
    } else
      tmp_node = tmp_node->previous; /* Iterating back*/
  }
}

int print_len_array(struct linear_list *list) {
  int counter = 0;
  while (list->previous != NULL) {
    ++counter;
  }
  printf("Array len [%d]", counter);
  return counter;
}
