#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

/* Swap two node using their memory addresses */
void swap_node(void *A, void *B) {
  void *temp = NULL;
  temp = A;
  A = B;
  B = temp;
  free(temp);
  /* have swap [A] after call this method */
  return;
}

/* TIMING - BENCHMARKS */
struct timeval *get_time() {
  struct timeval *start = malloc(sizeof(struct timeval));
  gettimeofday(start, NULL);
  return start;
}

double getTimeElapsed(struct timeval end, struct timeval start) {
  return (end.tv_sec - start.tv_sec) +
         (end.tv_usec - start.tv_usec) / 1000000.00;
}

double get_time_elapsed(struct timeval *start_time) {
  struct timeval *end_time = get_time();
  double time_spent = getTimeElapsed(*end_time, *start_time);
  free(end_time);
  free(start_time);
  return time_spent;
}

/*
int main(){

  struct timeval *start = get_time();
  sleep(1);
  double data = get_time_elapsed(start);
  printf("%f",data);
  return 0;
}
*/
