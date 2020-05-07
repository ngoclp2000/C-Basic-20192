#include <stdio.h>
#include "dllist.h"

int main() {

  dllist l = create_list();
  node_t p;

  l = insert_after(l,l,1);
  l = insert_after(l,l,2);
  l = insert_after(l,l,3);

  for (p = l; p != NULL; p = p->next)
    printf("%d,", p->data);
  printf("\n");

  if (find(l, 2) != NULL) {
    printf("Correct!\n");
  }

  if (find(l, 4) == NULL) {
    printf("Correct!\n");
  }
  free_list(l);
  if(l == NULL) printf("NULL\n");
  printf("%d\n",l->next->data);
  return 0;
}
