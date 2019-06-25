/*
 * Data una matrice A e uno scalare k, scrivvere le seguenti funzioni:
 *
 * - Funzione che restituisce la matrice B = k*A;
 * - Funziona che restituisce la matrice C = A/k;
 *
 * * */
#include "../datastructures.c"

struct matrice *scalar_mul(struct matrice *matrix, int k) {
  int i;
  int j;
  struct matrice *scalar_mul =
      populate_empty_matrix(matrix->n_righe, matrix->n_colonne, "SCALAR_MUL");
  for (i = 0; i < matrix->n_righe; i++) {
    for (j = 0; j < matrix->n_colonne; j++) {
      scalar_mul->matrix[i][j] = matrix->matrix[i][j] * k;
    }
  }
  pretty_print(scalar_mul);
  return scalar_mul;
}

struct matrice *scalar_div(struct matrice *matrix, int k) {
  int i;
  int j;
  struct matrice *scalar_mul =
      populate_empty_matrix(matrix->n_righe, matrix->n_colonne, "SCALAR_MUL");
  for (i = 0; i < matrix->n_righe; i++) {
    for (j = 0; j < matrix->n_colonne; j++) {
      scalar_mul->matrix[i][j] = matrix->matrix[i][j] / (float)k;
    }
  }
  pretty_print(scalar_mul);
  return scalar_mul;
}

int main() {

  int n_righe;
  int n_colonne;
  int scalar;
  printf("\nInserire il numero di righe: ");
  scanf("%d", &n_righe);
  printf("\nInserire il numero di righe: ");
  scanf("%d", &n_colonne);
  printf("\nInserire scalare [k]: ");
  scanf("%d", &scalar);

  struct matrice *matrix_A = (struct matrice *)malloc(sizeof(struct matrice));
  struct matrice *matrix_B = (struct matrice *)malloc(sizeof(struct matrice));

  populate_matrix(matrix_A, n_righe, n_colonne, "MATRIX_A");

  struct matrice *k_mul = scalar_mul(matrix_A, scalar);
  struct matrice *k_div = scalar_div(k_mul, scalar);
  free(matrix_A);
  free(matrix_B);
  free(k_mul);
  free(k_div);
}
