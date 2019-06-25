/*
 * Date due matrici diagonali quadrate (chiamate 'A' e 'B') scrivere i seguenti
 *metodi:
 * - Prodotto tra matrici --> A * B --> C
 * - Assegnamento della nuova 'matrice prodotto' ad A ( A --> C)
 *
 * */
#include <stdio.h>
#include <stdlib.h>
/* ======== STRUCTURE ========= */
struct matrice {
  char *nome;
  int n_righe;
  int n_colonne;
  int **matrix;
};
/* ======= es1.12p.h ======= */
// Initialize a new empty matrix allocating the necessary space in input
int **init_matrix(int righe, int colonne);

// Populate the given square matrix with the given data
void populate_matrix(struct matrice *matrix, int square_dimension, char *name);

// Return a new matrix with the given properties in input
struct matrice *populate_empty_matrix(int n_righe, int n_colonne, char *name);

// Verify that product can be applied from two matrix
int validate_dimension(struct matrice *A, struct matrice *B);

// Core function for calculate product from two given matrix. Return a new
// matrix
struct matrice *calculate_product(struct matrice *matrix_A,
                                  struct matrice *matrix_B);

// Pretty visualize the matrix
void pretty_print(struct matrice *matrix);

int **init_matrix(int righe, int colonne) {
  int i;
  int **matrix = (int **)malloc(righe * sizeof(int *));
  for (i = 0; i < righe; i++)
    matrix[i] = (int *)malloc(colonne * sizeof(int));
  return matrix;
}

void populate_matrix(struct matrice *matrix, int square_dimension, char *name) {
  matrix->n_righe = square_dimension;
  matrix->n_colonne = square_dimension;
  matrix->matrix = init_matrix(matrix->n_righe, matrix->n_colonne);
  matrix->nome = name;
  int i;
  int j;
  int tmp_value = 1;
  printf("Creazione matrice di dimensione %d ...", square_dimension);
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
      printf("%d     ", matrix->matrix[row][columns]);
    }
    printf("\n");
  }
}

int main() {
  // Matrice A
  struct matrice *matrix_A = (struct matrice *)malloc(sizeof(struct matrice));
  struct matrice *matrix_B = (struct matrice *)malloc(sizeof(struct matrice));
  int dim = 0;
  printf("Inserisci dimensione matrice quadrata: ");
  scanf("%d", &dim);
  populate_matrix(matrix_A, dim, "MATRIX_A");
  pretty_print(matrix_A);
  populate_matrix(matrix_B, dim, "MATRIX_B");
  pretty_print(matrix_B);
  struct matrice *matrix_C = calculate_product(matrix_A, matrix_B);
  pretty_print(matrix_C);
  free(matrix_A);
  free(matrix_B);
  free(matrix_C);
  return 0;
}
