#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lista.h"

struct node *init_node(int value) {
  struct node *head = NULL;
  head = malloc(sizeof(struct node));
  if (!head) {
    printf("\nOut of memory!!");
    return NULL;
  }

  head->value = value;
  head->next = NULL;
  return head;
}

void add_node(struct node **head, int value) {

  if (*head == NULL) {
    *head = init_node(value);
    printf("\nRoot node initialized [%d]", value);
    return;
  }

  struct node *temp = *head;

  while (temp->next != NULL) {
    temp = temp->next;
  }
  printf("\nAdding node %d", value);
  temp->next = init_node(value);
  return;
}

void print_node(struct node *head) {
  if (head == NULL) {
    printf("\nprint_node | Call the init function, there is no list there :D");
  }
  printf("\n");
  while (head != NULL) {
    printf("%d%s", head->value, (head->next != NULL) ? " | " : "");
    head = head->next;
  }
  return;
}

int remove_node(struct node **head, int value) {
  printf("\nRemove node | Checking if root exist ...");
  if (*head == NULL) {
    printf("\nCall the init function, list empty!");
    return -1;
  } else if ((*head)->value == value) {
    printf("\nFound in root! %d", value);
    *head = (*head)->next;
    return value;
  }

  printf("\nRemove node | root exist, iterating list ...");
  /* Used for iterate the list */
  struct node *current = (*head)->next;
  /* Used for swap the next element */
  struct node *swap_node = NULL;

  printf("\nremove_node | iterating value ...");
  while (current->next != NULL) {
    if (current->next->value == value) { /* Data found! */
      swap_node = current->next;
      current->next = swap_node->next;
      free(swap_node);

      // current = (*head)->next; /* try with current->next*/
      // free(*head);
      //*head = current;

      printf("\n Data %d found!", value);
      return value;
    }
    current = current->next;
  }
  printf("\nData not found - last");
  return -1;
}

/* Init n sequential node */
void init_n_node(struct node **head, int n) {

  clock_t begin = clock();
  int i;
  for (i = 0; i < n; i++) {
    add_node(head, i);
  }
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  float it = (float)n / time_spent;
  printf("init_n_node | Add %d element in %f [%f it/s]", n, time_spent, it);
}
