#include "list.h"

List		*List_new()
{
  List		*l;

  l = malloc(sizeof(*l));
  if (!l)
    return NULL;
  l->count = 0;
  l->first = NULL;
  l->last = NULL;
  return l;
}
