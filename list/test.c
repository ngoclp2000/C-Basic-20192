#include <stdio.h>
#include "list.h"

int main() {

  list l = create_list();
  node_t p;

  l = insert_before(l,l,1);
  l = insert_before(l,l,2);
  l = insert_before(l,l,3);

  for (p = l; p != NULL; p = p->next)
    printf("%d,", p->data);
  printf("\n");

  if (find(l, 2) != NULL) {
    printf("Correct!\n");
  }

  if (find(l, 4) == NULL) {
    printf("Correct!\n");
  }
  printf("%d\n",nth(l,1)->data);
  return 0;
}
