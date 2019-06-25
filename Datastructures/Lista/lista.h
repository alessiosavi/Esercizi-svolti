#include <stdlib.h>
#include <stdio.h>
#include <time.h>
struct node {

  int value;
  struct node *next;
};

struct node *init_node(int value);

/* Swap two node using their address */
void swap_node(struct node **A, struct node **B);

void add_node(struct node **head, int value);

/* Add a new node to the begin of the list */
void add_node_root(struct node **, int value);

int remove_node(struct node **head, int value);

void print_node(struct node *head);

void init_n_node(struct node **head, int n);
