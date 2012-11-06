#include "list.h"

bool		List_append(List *l, void * data)
{
  List_Iterator *new_it;

  new_it = malloc(sizeof(*new_it));
  if (!new_it)
    return false;

  new_it->data = data;
  new_it->next = NULL;

  if (!COUNT(l)) // empty set
    {
      l->first = new_it;
      l->last = new_it;
      new_it->prev = NULL;
    }
  else
    {
      new_it->prev = LAST(l);
      l->last->next = new_it;
      l->last = new_it;
    }
  l->count++;
  return true;
}

bool		List_prepend(List *l, void *data)
{
  List_Iterator	*new_it;

  new_it = malloc(sizeof(*new_it));
  if (!new_it)
    return false;

  new_it->data = data;
  new_it->next = FIRST(l);
  new_it->prev = NULL;

  l->first->prev = new_it;

  l->first = new_it;

  return true;
}
