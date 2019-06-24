#include <stdlib.h>
#include <stdio.h>

typedef struct node
{

  int value;
  struct node *next;

} node_t;

/* Init the root node of the list*/
node_t*
init_node (int value);

/* Print every element and return the size of the array */
int
print_node (node_t *head);

/* Link a new node to the last element of the list */
void
add_node (node_t **node, int value);

/* Remove the first occurence of 'value' from the list */
node_t*
remove_node (node_t **head, int value);

  void
display (node_t *head)
{
  node_t *it;

  for (it = head; it != NULL; it = it->next)
    printf (it->next != NULL ? "%d " : "%d\n", it->value);
}

  node_t*
init_node (int value)
{
  /* Allocate the space for the new node */
  node_t *node = malloc (sizeof(node_t));
  /* Use the value in input as data */
  node->value = value;
  /* No other element, NULL as next */
  node->next = NULL;
  return node;
}

  int
print_node (node_t *head)
{
  int size = 0;
  /* Make a copy of the pointer to the first element for iterate the list */
  node_t *it = head;
  printf ("\nNode POS [%d] | VALUE [%d] ", size, it->value);
  while (it->next != NULL)
  {
    printf ("\nNode POS [%d] | VALUE [%d] ", ++size, it->value);
    ++size;
    it = it->next;
  }
  return size;
}

  void
add_node (node_t **node, int value)
{

  if (node == NULL)
  {
    printf ("\nadd_node | Call the init_node function before use the list\n");
    return;
  }

  /* Root node is alredy populated, so we start from 1 */
  int counter = 1;
  /* Iterator for the node */
  node_t *it = *node;

  // Iterating list ...
  while (it->next != NULL)
  {
    ++counter;
    it = it->next;
  }

  printf ("\nInserting element [%d] in position %d", value, counter);
  it->next = init_node(value);
  return;
}

  node_t*
remove_node (node_t **head, int value)
{
  node_t *node = *head;
  if (node == NULL)
  {
    printf ("\nadd_node | Call the init_node function before use the list\n");
    return NULL;
  }

  int position = 0;
  /* Check in root node */
  if (node->value == value)
  {
    printf ("\nremove_node | Deleting root node ");
    /* Copy the element for return */
    node_t *tmp = init_node (node->value);
    /* Swap the element with the next one */
    if (node->next != NULL)
    {
      //free (node);
      *node = *node->next;
    }
    else
    {
      free (node);
    }
    return tmp;
  }
  /* Iterator for the node */
  node_t *it = node;

  // Iterating list ...
  while (it->next != NULL)
  {
    ++position;
    if (it->next->value == value)
    {
      printf ("\nremove_node | Removing --> [%d] | POS: [%d]", value,
          position);
      node_t *tmp = init_node (it->next->value); /* element to remove */
      if (it->next->next != NULL)
      {
        free (it->next);
        *it->next = *it->next->next;
      }
      else
      {
        printf ("\nremove_node | Deleting last element!");
        // Latest element
        free (it->next);
        it->next = NULL;
      }
      return tmp;
    }
    it = it->next;
  }
  printf ("\nremove_node | Element not found");
  return NULL;
}



void test1(){
  printf("\n=======================TEST1=====================");
  node_t *head = init_node(1);
  add_node(&head,2);
  add_node(&head,3);
  add_node(&head,4);
  add_node(&head,5);
  add_node(&head,6);
  print_node(head);
  free(head);
  printf("\n=======================TEST1=====================");
}

void test2(){
  printf("\n=======================TEST2=====================");
  node_t *head = init_node(1);
  add_node(&head,2);
  add_node(&head,3);
  add_node(&head,4);
  remove_node(&head,4);
  print_node(head);
  free(head);
  printf("\n=======================TEST2=====================");

}


  int
main ()
{
  test1();
  test2();
  node_t *head = init_node(1);
  add_node(&head,2);
  add_node(&head,3);
  add_node(&head,4);
  remove_node(&head,1);
  print_node(head);
  free(head);




}
