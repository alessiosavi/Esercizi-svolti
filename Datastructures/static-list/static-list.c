#include "static-list.h"

/* Enable logging */
#define DEBUG 1

void print_int_array(int *array, int size) {

  if (array == NULL) {
    printf("\nprint_int_array | ARRAY DATA not initialized");
    return;
  }
  int i;

  for (i = 0; i < size; i++) {
    printf(" %d |", array[i]);
  }
}

/* Shift the value of the array and allocate a new one of a given size
 * The method is delegated to delete the element of index 'counter' shifting the
 * content
 * of the array. The portion of the array since 'counter' will be copied into
 * the new allocated array;
 * then the other part of the data (starting from 'counter+1) will be copied.
 * */

int *sub_array(int *B, int new_size, int size_used, int counter) {

  /* Be sure that the value that we want to shift is enclosed in the array size
  */
  if (counter > size_used || counter < 0) {
    /*TODO: Print a message for every error cause */
    printf("\nsub_array | TODO: MANAGE ERROR!!!");
    return B;
  }

  /* This array will contains the new data */
  int *new_list = malloc(new_size * sizeof(int));

  /* Copy the size of (n element before * int size) from the input array
   * starting from first element [*array -> array[0]]*/
  printf("\nsub_array  | COPYING FIRST %d elements ...", counter);
  memcpy(new_list, B, (counter) * sizeof(int));

#ifdef DEBUG
  printf("\nNew list data after memcopy-> ");
  print_int_array(new_list, new_size);
#endif

  /* Copy everything starting from the end of the size that we have copied
   * before from counter until the last element that the array contains */
  printf("\nCopying %d elements starting from %d", (size_used - counter),
         counter);
  memcpy(&new_list[counter], &B[counter + 1],
         (new_size - counter) * sizeof(int));
#ifdef DEBUG
  printf("\nNew list data after memcopy-> ");
  print_int_array(new_list, new_size);
#endif

  if (counter == new_size) {
    printf("\nsub_array | Not necessary to initialize memory, array full!");
  } else {
    printf("\nInitializing with -1 from %d for %d elements", counter,
           (new_size - counter));
    /* Setting -1 starting from the last element of the list till the end */
    printf("\nInitializing : %d", new_size - counter);
    memset(&new_list[counter], -1, (new_size - counter) * sizeof(int));
  }

#ifdef DEBUG
  printf("\nNew list data after memset> ");
  print_int_array(new_list, new_size);
#endif
  return new_list;
}

void print_nodes(struct list *data) {

  if (data == NULL) {
    printf("\nprint_nodes | Data null!!");
  } else {
    print_int_array(data->array, data->max_size);
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

// void add_node_by_index(struct list **data,int value, int index){}

void remove_node_by_index(struct list **data, int index) {

  /* Be sure that the list and the array are (at least) allocated */
  if (*data == NULL || (*data)->array == NULL) {
    printf("\nremove_node | LIST EMPTY!");
    return;
  }

  /* Be sure that the element have the value in that position */
  if (index <= (*data)->size) {
  }
}

void remove_node(struct list **data, int value) {

  /* Be sure that the list and the array are (at least) allocated */
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
  printf("\nRemove_node | Data [%d] not found ... ", value);
}

struct list *init_n_node(int n) {
  struct list *list = NULL;

  int i;
  for (i = 0; i < n; i++) {
    add_node(&list, i);
  }
  return list;
}

void test_01(int t, int max) {

  printf("\n========== TEST %d ==========\n", t);
  char *test_msg = "Insert element and remove root node";
  printf("\n%s %d element\n", test_msg, max);

  struct list *list = init_n_node(max);
  print_nodes(list);
  struct timeval *start = get_time();
  remove_node(&list, 0);
  free(list);
  get_time_elapsed(start);
  print_nodes(list);
}

void test_02(int t, int max) {

  printf("\n========== TEST %d ==========\n", t);
  char *test_msg = "Insert element and remove mid node";
  printf("\n%s %d element\n", test_msg, max);
  struct list *list = init_n_node(max);
  print_nodes(list);
  struct timeval *start = get_time();
  remove_node(&list, max / 2);
  free(list);
  get_time_elapsed(start);
  print_nodes(list);
}
void test_03(int t, int max) {
  printf("\n========== TEST %d ==========\n", t);
  char *test_msg = "Insert element and remove last node";
  printf("\n%s %d element\n", test_msg, max);
  struct list *list = init_n_node(max);
  print_nodes(list);
  struct timeval *start = get_time();
  remove_node(&list, max - 1);
  free(list);
  get_time_elapsed(start);
  print_nodes(list);
}
void test_04(int t, int max) {
  printf("\n========== TEST %d ==========\n", t);
  char *test_msg = "Insert element and try to remove a non existing node";
  printf("\n%s %d element\n", test_msg, max);
  struct list *list = init_n_node(max);
  print_nodes(list);
  struct timeval *start = get_time();
  remove_node(&list, max);
  free(list);
  get_time_elapsed(start);
  print_nodes(list);
}
void test_10(int t, int max) {
  printf("\n========== TEST %d ==========\n", t);
  char *test_msg = "Execution time of insert";
  printf("\n%s %d element\n", test_msg, max);
  int i;
  struct timeval *start = get_time();
  struct list *list = init_list(MIN_LIST_LENGHT, -1);
  for (i = 0; i < max; ++i) {
    add_node(&list, i);
  }
  get_time_elapsed(start);
  printf("\n========== TEST %d | STOP ==========\n", t);
}

void test_sub_array01() {

  printf("\ntest_sub_array01 | Init int array of 4 element, then swap with "
         "counter > size");
  int test[4] = { 0, 1, 2, 3 };
  int i = 0;

  printf("\nTEST:\n");
  for (i = 0; i < 4; i++)
    printf("%d |", test[i]);

  printf("\nSwapping array ...");
  int *swap = sub_array(test, 4, 4, 5);
  printf("\nArray swapped!");
  printf("\nSWAP:\n");
  for (i = 0; i < 4; i++)
    printf("%d |", swap[i]);
}

void test_sub_array02() {

  printf("\ntest_sub_array02 | Init int array of 4 element, then swap with "
         "counter < size");
  int test[4] = { 0, 1, 2, 3 };
  int i = 0;

  printf("\nTEST:\n");
  for (i = 0; i < 4; i++)
    printf("%d |", test[i]);

  printf("\nSwapping array ...");
  int *swap = sub_array(test, 4, 4, 3);
  printf("\nArray swapped!");
  printf("\nSWAP:\n");
  for (i = 0; i < 4; i++)
    printf("%d |", swap[i]);
}
void test_sub_array03() {

  printf("\ntest_sub_array03 | Init int array of 4 element, then swap with "
         "counter = size");
  int test[4] = { 0, 1, 2, 3 };
  int i = 0;

  printf("\nTEST:\n");
  for (i = 0; i < 4; i++)
    printf("%d |", test[i]);

  printf("\nSwapping array ...");
  int *swap = sub_array(test, 4, 4, 4);
  printf("\nArray swapped!");
  printf("\nSWAP:\n");
  for (i = 0; i < 4; i++)
    printf("%d |", swap[i]);
}

void test_sub_array04() {

  printf("\ntest_sub_array04 | Init int array of 4 element, then swap with "
         "counter = size-1");
  int test[4] = { 0, 1, 2, 3 };
  int i = 0;

  printf("\nTEST:\n");
  for (i = 0; i < 4; i++)
    printf("%d |", test[i]);

  printf("\nSwapping array ...");
  int *swap = sub_array(test, 4, 4, 3);
  printf("\nArray swapped!");
  printf("\nSWAP:\n");
  for (i = 0; i < 4; i++)
    printf("%d |", swap[i]);
}
void test_sub_array05() {

  printf("\ntest_sub_array05 | Init int array of 4 element, then swap with "
         "counter = size-2");
  int test[4] = { 0, 1, 2, 3 };
  int i = 0;

  printf("\nTEST:\n");
  for (i = 0; i < 4; i++)
    printf("%d |", test[i]);

  printf("\nSwapping array ...");
  int *swap = sub_array(test, 4, 4, 4);
  printf("\nArray swapped!");
  printf("\nSWAP:\n");
  for (i = 0; i < 4; i++)
    printf("%d |", swap[i]);
}
void test_sub_array() {
  test_sub_array01();
  test_sub_array02();
  test_sub_array03();
  test_sub_array04();
  test_sub_array05();
}

int main() {

  /*
     int test_size = 20000;
     test_01(1, test_size);
     test_02(2, test_size);
     test_03(3, test_size);
     test_04(4, test_size);
  //  test_10(10, 10000);
  */
  test_sub_array();

  return 0;
}
