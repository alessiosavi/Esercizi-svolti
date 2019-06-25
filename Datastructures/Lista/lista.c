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

/* Swap two node using their memory addresses */
void swap_node(struct node **A, struct node **B) {
  struct node *temp = NULL;
  temp = *A;
  *A = *B;
  *B = temp;
  // free(temp); /*FIXME: This will panic!! You have to free the object that you
  // have swap [A] after call this method */
  return;
}

void add_node_root(struct node **head, int value) {

  /* Init ROOT node */
  if (*head == NULL) {
    *head = init_node(value);
    printf("\nRoot node initialized [%d]", value);
  } else if ((*head)->next == NULL) {
    /* No other element except root, replacing! */
    printf("\nReplacing root node with [%d]", value);
    *head = init_node(value);
  } else {

    struct node *root = init_node(value);
    root->next = *head;
    *head = root;

    /*
     * struct node *root = init_node(value);
    root->next = (*head)->next;
    swap_node(&root, head);
    free(root);
    */
  }
}

/*
 * add_node is delegated to initalize a new node and add to the list.
 * If the pointer passed in input is related to a NULL object, it will
 *  initialize a new root node
 * Input:
 *  - head -> memory address of pointer to 'node object' (pointer to -> struct
 *   node *head);
 *  - value -> data to store;
 * */

void add_node(struct node **head, int value) {
  if (*head == NULL) {
    *head = init_node(value);
    printf("\nRoot node initialized [%d]", value);
    return;
  }

  /* Copy the ELEMENT from the pointer in input */
  struct node *temp = *head;

  /* Iterating element until there is no next */
  while (temp->next != NULL) {
    temp = temp->next;
  }
  /* At this point the node (temp->next) is NULL, so we are going to add a new
   * node */
  // printf("\nAdding node %d", value);
  temp->next = init_node(value);
  return;
}

void print_node(struct node *head) {
  if (head == NULL) {
    printf("\nprint_node | Call the init function, there is no list there :D");
    return;
  }
  printf("\n");
  while (head != NULL) {
    printf("%d%s", head->value, (head->next != NULL) ? " | " : "");
    head = head->next;
  }
  return;
}

int remove_node(struct node **head, int value) {
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

  printf("\nremove_node | iterating value ...");
  while (current->next != NULL) {
    if (current->next->value == value) { /* Data found! */

      struct node *swap = NULL;
      swap = current->next;
      current->next = swap->next;
      free(swap);

      // current = (*head)->next;
      // free(*head);
      //*head = current;

      printf("\n Data %d found!", value);
      return value;
    }
    current = current->next;
  }
  printf("\nData not found");
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
  printf("\ninit_n_node | Add %d element in %f [%f it/s]", n, time_spent, it);
}

// int main(){return 0 ;}
