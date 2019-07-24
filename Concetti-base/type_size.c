#include <stdlib.h>
#include <stdio.h>


int main () {
  printf("\nPrint the size for every primitive data: \n");

  
/* Signed */
  int size_int = sizeof(int)*1;
  float size_float = sizeof(float)*1;
  double size_double = sizeof(double)*1;
  long size_long = sizeof(long)*1;
  long long size_long_long = sizeof(long long)*1;
  printf("\nWith sign:\n");

  printf("Int %d\n",size_int);
  printf("Double %f\n",size_float);
  printf("Float %f\n",size_double);
  printf("Long %ld\n",size_long);
  printf("Long long %lld\n",size_long_long);


  unsigned int u_size_int = sizeof(unsigned int)*1;
  // unsigned float u_size_float = sizeof(unsigned float)*1;
  // unsigned double u_size_double = sizeof(unsigned double)*1;
  unsigned long u_size_long = sizeof(unsigned long)*1;
  unsigned long long u_size_long_long = sizeof(unsigned long long)*1;
  printf("\nUnsigned :\n");

  printf("Int %d\n",u_size_int);
  // printf("Double %f\n",u_size_float);
  // printf("Float %f\n",u_size_double);
  printf("Long %ld\n",u_size_long);
  printf("Long long %lld\n",u_size_long_long);




return 0;

}
