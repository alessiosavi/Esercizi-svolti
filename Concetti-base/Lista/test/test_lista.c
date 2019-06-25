#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "test_lista.h"
#include "../lista.c"

void test01(int MAX) {
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

  printf("\n================= TEST 01 =================\n");
}

void test02(int MAX) {
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
  printf("\n================= TEST 02 =================\n");
}

void test03(int MAX) {
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
  printf("\n================= TEST 03 =================\n");
}

void test04(int MAX) {
  char test_04[200];
  snprintf(
      test_04, 200,
      "\nInit from 0 to %d, then try to remove a node the\n does not exist\n",
      MAX);
  printf("\n================= TEST 04 =================\n %s", test_04);
  struct node *head = NULL;

  init_n_node(&head, MAX);
  // print_node(head);
  remove_node(&head, MAX);
  // print_node(head);
  free(head);
  printf("\n================= TEST 04 =================\n");
}

int main() {

  int MAX = 10000;
  test01(MAX);
  test02(MAX);
  test03(MAX);
  test04(MAX);
  return 0;
}
