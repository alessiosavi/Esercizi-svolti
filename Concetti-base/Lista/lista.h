#include <stdlib.h>
#include <stdio.h>
#include <time.h>
struct node {

  int value;
  struct node *next;
};

struct node *init_node(int value);

void add_node(struct node **head, int value);

int remove_node(struct node **head, int value);

void print_node(struct node *head);

void init_n_node(struct node **node, int n);
