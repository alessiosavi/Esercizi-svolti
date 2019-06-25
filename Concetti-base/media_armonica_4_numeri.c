#include <stdio.h>
#include <stdlib.h>
#define PI 3, 14159

// FUNZIONE CHE CALCOLA MEDIA ARMONICA DI 4 NUMERI

// DICHIARAZIONE

float Media_Armonica(int *x, int *y, int *w, int *z);

float media_armonica(int a, int b, int c, int d);
// MAIN

int main() {

  int a;
  int b;
  int c;
  int d;
  float e;
  char s;
  int exit_required = 0;
  while (exit_required == 0) {
    printf("\n\nPuoi calcolare la media armonica di 4 numeri\n");

    printf("Premi y se vuoi fare il calcolo, x se vuoi uscire\n");
    scanf("%c", &s);

    switch (s) {
    case 'y':

      printf("scrivi il primo numero\n");
      scanf("%d", &a);

      printf("scrivi il secondo numero\n");
      scanf("%d", &b);

      printf("scrivi il terzo numero\n");
      scanf("%d", &c);

      printf("scrivi il primo numero\n");
      scanf("%d", &d);

      // e=Media_Armonica(&a,&b,&c,&d);
      e = media_armonica(a, b, c, d);

      printf("La media armonica di %d, %d, %d, e %d e'\n", a, b, c, d);
      printf("%f\n", e);
      break;

    case 'x':
      exit_required = 1;
      break;

    default:
      printf("puoi scegliere se fare il calcolo premendo s\n");
      printf("oppure uscire premendo x");
      // return -1;
      break;
    }
  }
  return 0;
}

// DEFINIZIONE FUNZIONE

float Media_Armonica(int *x, int *y, int *w, int *z) {

  float t;
  float one = 1 / *x;
  float two = 1 / *y;
  float three = 1 / *w;
  float four = 1 / *z;
  float e = one + two + three + four;
  t = 4 / e;

  return t;
}

float calculate_reciproco(int a) { return (float)1 / (float)a; }

float media_armonica(int a, int b, int c, int d) {

  float sum = calculate_reciproco(a);
  sum += calculate_reciproco(b);
  sum += calculate_reciproco(c);
  sum += calculate_reciproco(d);

  return (float)4 / sum;
}
