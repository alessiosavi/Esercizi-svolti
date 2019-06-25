
#include "test_lista.h"

double getTimeElapsed(struct timeval end, struct timeval start) {
  return (end.tv_sec - start.tv_sec) +
         (end.tv_usec - start.tv_usec) / 1000000.00;
}

void test01(int MAX) {

  struct timeval *start, *end;
  start = malloc(sizeof(struct timeval));
  end = malloc(sizeof(struct timeval));
  gettimeofday(start, NULL);

  char test_01[200];
  snprintf(test_01, 200,
           "\nInit from 0 to %d, then try to remove a node the root\n", MAX);

  printf("\n================= TEST 01 =================\n %s", test_01);
  struct node *head = NULL;

  init_n_node(&head, MAX);
  print_node(head);
  remove_node(&head, 0);
  print_node(head);

  free(head);
  gettimeofday(end, NULL);
  double time_spent = getTimeElapsed(*end, *start);
  printf("\nExecution Time: %f", time_spent);
  free(start);
  free(end);

  printf("\n================= TEST 01 =================\n");
}

void test02(int MAX) {
  struct timeval *start, *end;
  start = malloc(sizeof(struct timeval));
  end = malloc(sizeof(struct timeval));
  gettimeofday(start, NULL);

  char test_02[200];
  snprintf(test_02, 200,
           "\nInit from 0 to %d, then try to remove a node the mid\n", MAX);

  printf("\n================= TEST 02 =================\n %s", test_02);
  struct node *head = NULL;
  init_n_node(&head, MAX);
  print_node(head);
  remove_node(&head, 5);
  print_node(head);

  free(head);

  gettimeofday(end, NULL);
  double time_spent = getTimeElapsed(*end, *start);
  printf("\nExecution Time: %f", time_spent);
  free(start);
  free(end);

  printf("\n================= TEST 02 =================\n");
}

void test03(int MAX) {
  struct timeval *start, *end;
  start = malloc(sizeof(struct timeval));
  end = malloc(sizeof(struct timeval));
  gettimeofday(start, NULL);

  char test_03[200];
  snprintf(test_03, 200,
           "\nInit from 0 to %d, then try to remove a node the last\n", MAX);

  printf("\n================= TEST 03 =================\n %s", test_03);
  struct node *head = NULL;

  init_n_node(&head, MAX);
  print_node(head);
  remove_node(&head, MAX - 1);
  print_node(head);

  free(head);

  gettimeofday(end, NULL);
  double time_spent = getTimeElapsed(*end, *start);
  printf("\nExecution Time: %f", time_spent);
  free(start);
  free(end);

  printf("\n================= TEST 03 =================\n");
}

void test04(int MAX) {
  struct timeval *start, *end;
  start = malloc(sizeof(struct timeval));
  end = malloc(sizeof(struct timeval));
  gettimeofday(start, NULL);

  char test_04[200];
  snprintf(
      test_04, 200,
      "\nInit from 0 to %d, then try to remove a node the\n does not exist\n",
      MAX);
  printf("\n================= TEST 04 =================\n %s", test_04);
  struct node *head = NULL;

  init_n_node(&head, MAX);
  print_node(head);
  remove_node(&head, MAX);
  print_node(head);
  free(head);

  gettimeofday(end, NULL);
  double time_spent = getTimeElapsed(*end, *start);
  printf("\nExecution Time: %f", time_spent);
  free(start);
  free(end);

  printf("\n================= TEST 04 =================\n");
}

void test05(int MAX) {
  struct timeval start, end;
  gettimeofday(&start, NULL);
  char test_05[200];
  snprintf(test_05, 200,
           "\nInit from 0 to %d, then try to add a new root node\n", MAX);
  printf("\n================= TEST 05 =================\n %s", test_05);
  struct node *head = NULL;

  init_n_node(&head, MAX);
  print_node(head);
  add_node_root(&head, -10);
  print_node(head);
  free(head);

  gettimeofday(&end, NULL);
  double time_spent = getTimeElapsed(end, start);
  printf("\nExecution Time: %f", time_spent);
  printf("\n================= TEST 05 =================\n");
}

int main() {

  int MAX = 10;
  test01(MAX);
  test02(MAX);
  test03(MAX);
  test04(MAX);
  test05(MAX);

  struct node *A = NULL;
  struct node *B = NULL;
  add_node(&A, 0);
  add_node(&B, 1);
  printf("\nTEST: A: %d | B: %d", A->value, B->value);
  swap_node(&A, &B);
  printf("\nTEST: A: %d | B: %d", A->value, B->value);

  return 0;
}
