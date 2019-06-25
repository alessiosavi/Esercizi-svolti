#include <stdlib.h>
#include <stdio.h>

struct node {

  int value;
  struct node *next;
};

struct node *init_node(int value);

void add_node(struct node **head, int value);

int remove_node(struct node **head, int value);

void print_node(struct node *head);

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

int main() {

  struct node *head = NULL;
  print_node(head);
  add_node(&head, 1);
  print_node(head);
  add_node(&head, 2);
  print_node(head);
  add_node(&head, 3);
  print_node(head);
  add_node(&head, 4);
  print_node(head);
  remove_node(&head, 1);
  print_node(head);
  remove_node(&head, 2);
  print_node(head);
  remove_node(&head, 3);
  print_node(head);
  remove_node(&head, 4);
  print_node(head);
  add_node(&head, 3);
  print_node(head);
  return 0;
}
