#include "unistd.h"
#include "list/list.h"

void		dump(void *data)
{
  char *c = (char*)(data);

  write(1, c, 1);
  write(1, "\n", 1);
}

int		main()
{
  List		*l = List_new();
  char		a = 'a', b = 'b', c = 'c';

  List_append(l, &a);
  List_prepend(l, &b);
  List_append(l, &c);

  List_foreach(l, &dump);

  return 0;
}
