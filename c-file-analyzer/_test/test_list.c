#include "../structures/static-list/static-list.c"
/* Used as list */

int main() {

  char *name = "alessio";
  char *path = "savi";

  struct list *list;
  list = init_list(1, name, path);

  add_node(&list, "alessio1", "savi1");
  add_node(&list, "alessio2", "savi2");

  print_nodes(list);
  printf("\n==================\n");
  remove_node(&list, "alessio2");
  printf("\n==================\n");

  print_nodes(list);

  free(list);

  return 0;
}
