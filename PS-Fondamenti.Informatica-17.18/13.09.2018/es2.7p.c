/*
 * Data una lista in forma collegata con i puntatori, scrivere una funzione che
 * ritorna due liste:
 * - Una con gli elementi divisibili per 3;
 * - Una con gli elementi divisibili per 5;
 *
 */

#include <stdlib.h>
#include <stdio.h>

#include "../../c-library/log.h"
#include "../../c-library/log.c"

typedef struct node {
  int value;
  struct node *next;
} node;

// Random utils

// Just for init random data
void random_init_seed();

// Generate a number X --> 1 <= X <= 'max'
int random_generate(int max);

// List utils

// Generate a new node
node *node_init(int value);

// Append a new node to the tail of the list
node *node_add(node *node, int value);

/* Iterate every node and delete the first node populated with 'value' */
node *remove_node(node *head, int value);
