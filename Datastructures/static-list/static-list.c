#include "static-list.h"

void print_nodes(struct list *data) {

  if (data == NULL) {
    printf("\nprint_nodes | Data null!!");
    return;
  }
  int i = 0;
  printf("\n");
  for (; i < data->max_size; i++) {
    printf(" %d |", data->array[i]);
  }
  printf("\n");
}

/* Initalize the structure that contains the data */
struct list *init_list(int size, int value) {

  /* FORCE to MIN_LIST_LENGHT */
  if (size <= 0) {
    size = MIN_LIST_LENGHT;
  }

  /* Creating uninitialized memory for the struct */
  struct list *list = malloc(sizeof(struct list));
  /* Be sure that the memory was really allocated */
  if (!list) {
    printf("\nOUT OF MEMORY!!");
    return NULL;
  }
  /* This will be the array that will contains the data */
  list->array = malloc(size * sizeof(int));
  if (!list->array) {
    printf("\nOUT OF MEMORY!!");
    free(list);
    return NULL;
  }
  /* the size rappresent the number of node inserted in the list (only the root
   * for now) */
  list->size =
      0; /* The node just add, will increase when the value will be set few
            instruction below */
  list->max_size = size; /* Parameter used for allocate the space */
  list->array[list->size++] =
      value; /* array that contains the value just inserted */
  return list;
}

/* Use the address of the struct for add a node the list */
void add_node(struct list **data, int value) {
  /* List is not initialized, init the first node */
  if (*data == NULL) {
    printf("\nadd_node | INIT ROOT NODE %d", value);
    *data = init_list(MIN_LIST_LENGHT, value);
  } else if /* check if is necessary to allocate a new element */
      ((*data)->size == (*data)->max_size) {
    /* List have reached the maximum space! Allocate some new fresh memory */

    /* Access and save the old size */
    int old_max_size = (*data)->max_size;
    /* Increase the size by a constant factor */
    int new_size = old_max_size + DEFAULT_INC;

    //   printf("\nadd_node | Allocate a new space for store %d", value);

    /*Allocate a new space for the data */
    int *new_list = malloc(new_size * sizeof(int));
    /* Copying the data ... (destination, source, size) */
    memcpy(new_list, (*data)->array, old_max_size * sizeof(int));
    /* Free the data */
    free((*data)->array);
    /* Copy the pointer to the data*/
    (*data)->array = new_list;
    /* Set the new max size*/
    (*data)->max_size = new_size;
    /* Add the element to the new list and use the post increment to increase
     * the size*/
    (*data)->array[(*data)->size++] = value;
  } else {
    //    printf("\nadd_node | Insert -> %d | POS: %d", value, (*data)->size);
    (*data)->array[(*data)->size++] = value;
  }
}

void remove_node(struct list **data, int value) {

  if (*data == NULL || (*data)->array == NULL) {
    printf("\nremove_node | LIST EMPTY!");
    return;
  }

  int counter = 0;
  /* Iterating the data ... */

  while (counter < (*data)->max_size) {
    /* Data found! */
    if ((*data)->array[counter] == value) {
      /* Delete the address copying the memory */

      int new_size = (*data)->max_size;
      /* This will contains the new data */
      int *new_list = malloc(new_size * sizeof(int));
      /* Copy everything before the element */
      memcpy(new_list, (*data)->array, (counter) * sizeof(int));
      /* Copy everything after the element */
      memcpy(&new_list[counter], &(*data)->array[counter + 1],
             ((*data)->max_size - (counter)) * sizeof(int));

      memset(&new_list[(*data)->size - 1], -1,
             ((*data)->max_size - (*data)->size + 1) * sizeof(int));

      /* Free the data */
      free((*data)->array);
      /* Copy the pointer to the data*/
      (*data)->array = new_list;
      /* Set the new max size*/
      (*data)->max_size = new_size;
      /* Decrease counter of the size */
      --(*data)->size;

      printf("\nremove_node | Value [%d] | POS: [%d] | Removed! ", value,
             counter);
      return;
    }
    ++counter;
  }
  printf("\remove_node | Data [%d] not found ... ", value);
}

void test_01(int t, int max) {
  printf("\n========== TEST %d ==========\n", t);
  char *test_msg = "Execution time of insert";
  printf("\n%s %d element\n", test_msg, max);
  int i;
  struct timeval *start = get_time();
  struct list *list = init_list(MIN_LIST_LENGHT, -1);
  for (i = 0; i < max; ++i) {
    add_node(&list, i);
  }
  double _time = get_time_elapsed(start);

  printf("\nExecution time = %f\n", _time);
}

int main() { test_01(1, 500000); }
