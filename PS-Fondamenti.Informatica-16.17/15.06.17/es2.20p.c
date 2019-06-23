#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../../c-library/log.h"
#include "../../c-library/log.c"

/*
 * Data una lista in forma collegata con puntatori, scrivere una funzione
 * che:
 * - Ritorna il numero di elementi della lista;
 * - Ritorna il massimo degli elementi della lista;
 *
 */


/*===== CONSTANT ==== */

#define MAX_LIST_LENGHT 20


/*===== es2.20p.h ==== */

typedef struct node  {
  int value;
  /* Absolute position from root node*/
  int index;
  struct  node *next;
  /* NOTE: The code logic use only the pointer to the next element */
  struct  node *previous;
} node_t;


node_t *init_node(int value);

node_t *add_node(node_t *head,int value);

node_t *remove_node(node_t *head,int value);

node_t *get_last_element(node_t *head);

int count_node(node_t *head);

int max(int a,int b);

/*===== es2.20p.c ==== */

/* Return a new node_t * with the given value */
node_t *init_node(int value)
{

  /* If -1 provided, generate a random number */
  if (value == -1 )
    value = rand()%20;
  log_debug("init_node | init node_t with value %d",value);
  node_t *head =(node_t *)malloc(sizeof(node_t)); /* Allocating struct memory space */
  head->value = value; /* Setting the value */
  head->next = NULL; /* NULL as next node_t */
  head->previous = NULL; /* NULL as previous node*/
  head->index = -1;
  return head;
}

node_t *add_node(node_t *head,int value)
{
  int c =0 ;
  /* Checking if is the root node_t */
  if (head == NULL){
    head = init_node(value);
    head->index =c;
    log_debug("add_node | Adding first node_t with value %d @position %d",head->value,c);
    return head;
  }
  ++c;
  node_t *tmp = head;
  while (tmp->next != NULL){
    tmp = tmp->next;
    log_info("add_node | Value: %d | Index: %d",tmp->value,tmp->index);
    ++c;
  }
  tmp->next = init_node(value);
  tmp->next->previous = head;
  tmp->next->index = c;
  log_debug("add_node | Adding node_t with value %d @position %d",tmp->next->value,c);
  return head;
}

node_t *remove_node(node_t *head,int value){
  int counter = 0;
  int confirm_removed = -1;
  node_t *tmp = NULL;

  /* No node_t */
  if (head == NULL){
    log_debug("remove_node | Init a new node_t before use the remove!");
    return NULL;
    /* Only one node_t */
  }else if (head->next == NULL){
    log_debug("remove_node | Only one element ...");
    if (head->value == value){
      log_debug("remove_node | Removing the only element %d in position %d",value,counter); 
      return NULL; 
    }
    log_debug("remove_node | Value %d not found ...",value);
    return head;
  }

  /* Checking root node_t */
  if (head->value == value){
    log_debug("remove_node | Deleting root node");
    /*FIXME->Nullpointer in case of no further element */
    return head->next; 
  }
  /* Make a copy */
  tmp = head; 
  while(tmp->next!=NULL){
    log_debug("remove_node | Analyzing node_t %d --> %d | POS: %d | VAL: %d ",counter,value,tmp->index,tmp->value);
    if (tmp->value == value){
      confirm_removed = 1;
      /* Discharge the element */
      log_debug("remove_node | Removing item %d in position %d",value,counter); 
      tmp->next = tmp->next->next;
      tmp->previous = tmp->previous->previous;
      break;
    }
    /*Going to the next element */
    tmp = tmp->next;
    ++counter;
  }

  if (confirm_removed != 1){
    log_error("remove_node | Data %d not found :/",value) ;

  }
  return head;
}




int main(){
  /* Necessary for init a random seed @runtime */
  srand ( time(0) );

  node_t *head = NULL;
#ifdef MAX_LIST_LENGHT
#undef MAX_LIST_LENGHT
#define MAX_LIST_LENGHT 2
#endif
  head = add_node(head,1);
  head = add_node(head,2);
  head = add_node(head,3);
  head = add_node(head,2);

  head = remove_node(head,1);
  head = remove_node(head,2);
  head = remove_node(head,2);
  head = add_node(head,1);
  head = add_node(head,2);
  head = remove_node(head,1);

  return 0;
}

