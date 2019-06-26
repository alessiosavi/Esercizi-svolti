#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../c-library/commons.c"
#define MIN_LIST_LENGHT 2
#define DEFAULT_INC 10

/*
 * Static list C implementation
 *
 * This datastructure contains an array that store the value that we want to save;
 * The array have a fixed size, once the array is full and the user try to insert a new 
 * node, the size will grow of DEFAULT_INC
 *
 * Structure
 * - int *array:
 *   the array contains the value that we want to store
 * - int size:
 *   number of value that the array contains
 * - int max_size:
 *   max number of value that the array can contains before allocate a new array
 * 
 * */
struct list {
  int *array;
  int size;
  int max_size;
};

/* Print the data related to the array associated to the list */
void print_nodes(struct list *data);

/* Take care about allocation process of the structure */
struct list *init_list(int size, int value);

/* Use the pointer of the structure for add a new value */
void add_node(struct list **data, int value);

/* Add or replace a node in a particular position */
void add_node_by_index(struct list **data,int value, int position);

/* Remove the data using memset */
void remove_node(struct list **data, int value);

/* Add or replace a node in a particular position */
void remove_node_by_index(struct list **data,int position);


/* Remove unnecessary allocated object */
void prune_list(struct list **list);

