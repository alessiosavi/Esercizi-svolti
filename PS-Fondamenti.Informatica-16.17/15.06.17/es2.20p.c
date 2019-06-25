/*
   ============================================================================
Name        : Lista.c
Author      : alessiosavi
Version     :
Copyright   : Your copyright notice
Description : Hello World in C, Ansi-style
============================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../../c-library/log.h"
#include "../../c-library/log.c"

/*
 * Data una lista in forma collegata con puntatori, scrivere una funzione
 * che:
 * - Ritorna il numero di elementi della lista;
 * - Ritorna il massimo degli elementi della lista;
 *
 */

/*===== CONSTANT ==== */

#define MAX_LIST_LENGHT 20

/*===== es2.20p.h ==== */

typedef struct node {
  int value;
  /* Absolute position from root node */
  int index;
  struct node *next;
  /* NOTE: The code logic use only the pointer to the next element */
  struct node *previous;
} node_t;

node_t *init_node(int value);

node_t *add_node(node_t *head, int value);

node_t *remove_node(node_t *head, int value);

node_t *get_last_element(node_t *head);

int count_node(node_t *head);

void display(node_t *head) {
  node_t *it;

  for (it = head; it != NULL; it = it->next)
    printf(it->next != NULL ? "%d " : "%d\n", it->value);
}

int max(int a, int b);

/*===== es2.20p.c ==== */

/* Return a new node_t * with the given value */
node_t *init_node(int value) {

  /* If -1 provided, generate a random number */
  if (value == -1)
    value = rand() % 20;
  log_debug("init_node | Creating node -> Value: [%d]", value);
  node_t *head =
      (node_t *)malloc(sizeof(node_t)); /* Allocating struct memory space */
  head->value = value;                  /* Setting the value */
  head->next = NULL;                    /* NULL as next node_t */
  head->previous = NULL;                /* NULL as previous node */
  head->index = -1;
  return head;
}

node_t *add_node(node_t *head, int value) {

  node_t *new_node = init_node(value);
  int c = 0;
  /* Checking if is the root node_t */
  if (head == NULL) {
    log_debug("add_node | Adding root node [%d] @position %d", value, c);
    new_node->index = c;
    head = new_node;
  } else {
    ++c;
    /* Make a copy of the pointer */
    node_t *tmp;

    for (tmp = head; tmp->next != NULL; tmp = tmp->next) {
      //      log_debug("add_node | Iterating list ... | Value: %d | Index: %d",
      // tmp->value, tmp->index);
      ++c;
    }
    //   log_debug("add_node | Iterating list ... | Value: %d | Index: %d",
    // tmp->value, tmp->index);
    new_node->previous = tmp;
    tmp->next = new_node;
    new_node->index = c;
    log_debug("add_node | Adding node with value %d @position %d",
              new_node->value, c);
  }
  return head;
}

node_t *remove_node(node_t *head, int value) {
  log_debug("remove_node | Removing value %d from list ...", value);
  int counter = 0;
  int confirm_removed = -1;
  node_t *tmp = NULL;

  /* No node_t */
  if (head == NULL) {
    log_debug("remove_node | Init a new node_t before use the remove!");
    return NULL;
    /* Only one node_t */
  } else if (head->next == NULL) {
    log_debug("remove_node | List have only one element ...");
    if (head->value == value) {
      log_debug("remove_node | Removing the only element %d in position %d",
                value, counter);
      return NULL;
    }
    log_debug("remove_node | Value %d not found ...", value);
    return head;
  }

  /* Checking root node_t */
  if (head->value == value) {
    log_debug("remove_node | Deleting root node");
    return head->next;
  }
  log_debug("remove_node | Iterating list ..");
  /* Make a copy */
  tmp = head;
  while (tmp->next != NULL) {
    log_debug("remove_node | Analyzing node_t %d --> %d | POS: %d | VAL: %d ",
              counter, value, tmp->index, tmp->value);
    if (tmp->value == value) {
      confirm_removed = 1;
      log_debug("remove_node | Removing item %d in position %d", value,
                counter);

      tmp->previous = tmp->previous->previous;
      tmp = tmp->next;
      return head;
    }
    /*Going to the next element */
    tmp = tmp->next;
    ++counter;
  }

  /* Checking last element */

  if (tmp->value == value) {
    log_debug("remove_node | Removing last item %d in position %d", value,
              counter);
    tmp->previous = tmp->previous->previous;
    tmp = tmp->next;
    return head;
  }

  if (confirm_removed != 1)
    log_debug("remove_node | Data %d not found :/", value);
  return head;
}
void test1() {
  log_debug("============= TEST 1 ===========");
  log_debug("Add and remove same element from an empty list ...");
  node_t *head = NULL;
  head = add_node(head, 1);
  display(head);
  head = remove_node(head, 1);
  display(head);
  log_debug("============= TEST 1 ===========");
}

void test2() {
  log_debug("============= TEST 2 ===========");
  log_debug("ADD: 2 same element");
  log_debug("REMOVE: First element");
  node_t *head = NULL;
  head = add_node(head, 1);
  head = add_node(head, 1);
  display(head);
  head = remove_node(head, 1);
  display(head);
  log_debug("============= TEST 2 ===========");
}

void test3() {
  log_debug("============= TEST 3 ===========");
  log_debug("ADD: 2 different element");
  log_debug("REMOVE: First element");
  node_t *head = NULL;
  head = add_node(head, 1);
  head = add_node(head, 2);
  display(head);
  head = remove_node(head, 1);
  display(head);
  log_debug("============= TEST 3 ===========");
}

void test4() {
  log_debug("============= TEST 4 ===========");
  log_debug("ADD: 2 different element");
  log_debug("REMOVE: Second element");
  node_t *head = NULL;
  head = add_node(head, 2);
  head = add_node(head, 1);
  display(head);
  head = remove_node(head, 1);
  display(head);
  log_debug("============= TEST 4 ===========");
}

void test5() {
  log_debug("============= TEST 5 ===========");
  log_debug("ADD: 2 same, 1 different element");
  log_debug("REMOVE: Last element");
  node_t *head = NULL;
  head = add_node(head, 2);
  head = add_node(head, 2);
  head = add_node(head, 1);
  display(head);
  head = remove_node(head, 1);
  display(head);
  log_debug("============= TEST 5 ===========");
}

void test6() {
  log_debug("============= TEST 6 ===========");
  log_debug("ADD: 2 same, 1 different element");
  log_debug("REMOVE: 2nd/3 element");
  node_t *head = NULL;
  head = add_node(head, 2);
  head = add_node(head, 1);
  head = add_node(head, 2);
  display(head);
  head = remove_node(head, 1);
  display(head);
  log_debug("============= TEST 6 ===========");
}

void test7() {
  log_debug("============= TEST 7 ===========");
  log_debug("ADD: 8 different node, root same as second");
  log_debug("REMOVE: root element");
  node_t *head = NULL;
  head = add_node(head, 1);
  display(head);
  head = add_node(head, 1);
  display(head);
  head = add_node(head, 2);
  display(head);
  head = add_node(head, 3);
  display(head);
  head = add_node(head, 4);
  display(head);
  head = add_node(head, 5);
  display(head);
  head = add_node(head, 6);
  display(head);
  head = add_node(head, 7);
  display(head);
  head = add_node(head, 8);
  display(head);
  head = remove_node(head, 1);
  display(head);
  log_debug("============= TEST 7 ===========");
}

int main() {
  /* Necessary for init a random seed @runtime */
  srand(time(0));

  node_t *head = NULL;
#ifdef MAX_LIST_LENGHT
#undef MAX_LIST_LENGHT
#define MAX_LIST_LENGHT 2
#endif
  head = add_node(head, 1);
  head = add_node(head, 1);
  head = add_node(head, 1);
  head = add_node(head, 1);
  head = add_node(head, 1);
  head = add_node(head, 1);

  head = remove_node(head, 1);

  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  return 0;
}
