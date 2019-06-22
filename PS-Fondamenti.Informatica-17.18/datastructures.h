struct matrice{
  char *nome;
  int n_righe;
  int n_colonne;
  long **matrix;
}; 

// Initialize a new empty matrix allocating the necessary space in input
long **init_matrix(int righe,int colonne);

// Populate the given square matrix with the given data
void populate_matrix(struct matrice *matrix, int n_righe,int n_colonne,char *name);

// Return a new matrix with the given properties in input
struct matrice *populate_empty_matrix(int n_righe,int n_colonne,char *name);

// Verify that product can be applied from two matrix
int validate_dimension(struct matrice *A, struct matrice *B);

// Core function for calculate product from two given matrix. Return a new matrix
struct matrice *calculate_product(struct matrice *matrix_A, struct matrice *matrix_B);

// Pretty visualize the matrix
void pretty_print(struct matrice *matrix);

