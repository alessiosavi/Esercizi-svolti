#include <stdio.h>
#include <stdlib.h>
#define N 5
#define k 2
#define t 2

/* Just for clear the screen */
#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr()                                                               \
  { printf("\e[1;1H\e[2J"); }
#endif

//----------------DICHIARAZIONE--------------
float medium_riga(int A[k][t], int i);

int get_iesima_riga();

//-----------------MAIN----------------------

int main() {
  int matrix[k][t] = { { 1, 3 }, { 4, 6 } };

  int input_utente = 100;
  float avg_result = -1;

  while (1) {
    input_utente = get_iesima_riga();
    if (input_utente == 1 || input_utente == 2) {
      /* Le macchine contano da O a N, noi da 1 a N, quindi diminuiamo 1*/
      --input_utente;
      avg_result = medium_riga(matrix, input_utente);
      printf("\nmain | la media della riga %d e' %f\n", input_utente,
             avg_result);
    } else if (input_utente == -1) {
      printf("\nmain | EXIT!\n");
      return 0;
    } else {
      printf("\nLa selezione %d non corrisponde a niente :/", input_utente);
    }
    printf("\nPremere un tasto per continuare ...");
    /*Flush the \n (new line)*/
    getchar();
    getchar();
    clrscr();
  }

  return 1;
}

int get_iesima_riga() {
  /*Effettuare scanf per prendere INPUT */
  int i_riga = 1;
  printf(
      "\nInserire il numero della riga [1,2] oppure -1 se si vuole uscire: \n");
  scanf("%d", &i_riga);
  // Sottrago 1 per avere un valore compliant con il mio indece di matrice (0-1)
  return i_riga;
}

float medium_riga(int A[k][t], int riga) {
  printf("\nmedium_riga | START");
  // Used for save the sequantial sum
  int sum = 0;
  // Used for return and print the average
  float media = 0;
  int x = 0;
  for (; x < t; x++) {
    printf("\nmedium_riga | Rows: %d | Index %d | Val: %d", riga, x,
           A[riga][x]);
    sum += (float)A[riga][x];
  }

  media = (float)sum / (float)t;
  printf("\nmedium_riga | Media -> %f", media);
  return media;
}
