#include "list.h"

void		List_foreach(List *l, list_cb cb)
{
  List_Iterator *it = FIRST(l);

  if (!it)
    return;
  while (it)
    {
      cb(it->data);
      it = NEXT(it);
    }
}
