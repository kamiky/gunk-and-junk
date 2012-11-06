#include "list.h"


static void	List_it_delete(List_Iterator *it)
{
  if (!it)
    return;
  if (!IS_LAST(it))
    List_it_delete(NEXT(it));
  free(it);
}

void		List_delete(List *l)
{
  List_it_delete(FIRST(l));
}
