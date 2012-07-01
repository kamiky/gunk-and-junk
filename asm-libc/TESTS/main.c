/*
** main.c for main.c in /home/empty/epitech/projets/asm/minilibc/
**
** Made by baptiste careil
** Login   <careil_b@epitech.net>
**
** Started on  Mon Feb 28 09:57:28 2011 baptiste careil
** Last update Mon Mar 14 12:05:38 2011 baptiste careil
*/

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <assert.h>

void		memcpy_test()
{
  char		arr[8];

  puts("==> [MEMCPY] Start");
  puts("-> memcpy(arr, \"abcdef\", 7)");
  assert(memcpy(arr, "abcdef", 7) == arr);
  puts(arr);
  puts("-> memcpy(&arr[3], arr, 3)");
  assert(memcpy(&arr[3], arr, 3) == &arr[3]);
  puts(arr);
  puts("==> [MEMCPY] End");
}

void		memmove_test()
{
  char		arr[32];

  puts("==> [MEMMOVE] Start");
  puts("-> memove(arr, \"abcdefghijklmnopqrstuvwxyz\", 27)");
  assert(memmove(arr, "abcdefghijklmnopqrstuvwxyz", 27) == arr);
  puts(arr);
  puts("-> memmove(&arr[4], arr, 27)");
  assert(memmove(&arr[4], arr, 27) == &arr[4]);
  puts(arr);
  puts("-> memmove(arr, &arr[4], 27)");
  assert(memmove(arr, &arr[4], 27) == arr);
  puts(arr);
  puts("==> [MEMMOVE] End");
}

void		memset_test()
{
  char		arr[6];

  puts("==> [MEMSET] Start");
  puts("-> memset(arr, 0, sizeof(arr));");
  assert(memset(arr, 0, sizeof(arr)) == arr);
  puts(arr);
  puts("-> memset(arr,'\\n', 5);");
  assert(memset(arr, '\n', 5) == arr);
  puts(arr);
  puts("-> memset(arr, 256 + 42, 4);");
  assert(memset(arr, 256 + 42, 4) == arr);
  puts(arr);
  puts("==> [MEMSET] End");
}

void		read_test()
{
  char		buffer[4096];
  ssize_t	ret;

  puts("==> [READ] Start");
  puts("-> read(0, buffer, sizeof(buffer) - 1) // sizeof(buffer) = 4096");
  if ((ret = read(0, buffer, sizeof(buffer) - 1)) >= 0)
    buffer[ret] = '\0';
  printf("bytes read:%i, content:%s$\n", ret, buffer);
  puts("-> ret = read(42, buffer, sizeof(buffer) - 1)");
  ret = read(42, buffer, sizeof(buffer) - 1);
  printf("bytes read : %u, ret == -1 ? %i\n", ret, ret == -1);
  perror("read");
  puts("==> [READ] End");
  errno = 0;
}

void		rindex_test()
{
  char		*ch;
  char		*str = "abcdefghijklmabcdefghijklm";

  puts("==> [RINDEX] Start");
  puts("-> rindex(str, 'a')");
  ch = rindex(str, 'a');
  printf("str={%p, %s}, ch={%p, %c}, ch-str=%i\n",
	 str, str,
	 ch, (ch == NULL ? '*' : *ch),
	 ch - str);
  puts("-> rindex(str, '$')");
  ch = rindex(str, '$');
  printf("str={%p, %s}, ch={%p, %c}, ch-str=%i\n",
	 str, str,
	 ch, (ch == NULL ? '*' : *ch),
	 ch - str);
  puts("==> [RINDEX] End");
}

void		strcasecmp_test()
{
  size_t	i;
  size_t	j;
  const char	*s[] =
    {
      "amen",
      "AMeN",
      "amen!",
      "AMeN!",
      "cctvvmb",
      NULL
    };

  puts("==> [STRCASECMP] Start");
  for (i = 0; s[i] != NULL; ++i)
    for(j = 0; s[j] != NULL; ++j)
      printf("-> strcasecmp(%s, %s) = %i\n", s[i], s[j],
	     strcasecmp(s[i], s[j]));
  puts("==> [STRCASECMP] End");
}

void		strchr_test()
{
  char		*ch;
  char		*str = "abcdefghijklmabcdefghijklm";

  puts("==> [STRCHR] Start");
  puts("-> strchr(str, 'a')");
  ch = strchr(str, 'a');
  printf("str={%p, %s}, ch={%p, %c}, ch-str=%i\n",
	 str, str,
	 ch, (ch == NULL ? '*' : *ch),
	 ch - str);
  puts("-> strchr(str, '$')");
  ch = strchr(str, '$');
  printf("str={%p, %s}, ch={%p, %c}, ch-str=%i\n",
	 str, str,
	 ch, (ch == NULL ? '*' : *ch),
	 ch - str);
  puts("==> [STRCHR] End");
}

void		strcmp_test()
{
  size_t	i;
  size_t	j;
  const char	*s[] =
    {
      "amen",
      "AMeN",
      "amen!",
      "AMeN!",
      "cctvvmb",
      NULL
    };

  puts("==> [STRCMP] Start");
  for (i = 0; s[i] != NULL; ++i)
    for(j = 0; s[j] != NULL; ++j)
      printf("-> strcmp(%s, %s) = %i\n", s[i], s[j],
	     strcmp(s[i], s[j]));
  puts("==> [STRCMP] End");
}

void		strcspn_test()
{
  char		*s = "Amen is watching you.";
  char		*reject = "abcdefghi";

  puts("==> [STRCSPN] Start");
  printf("-> strcspn(\"%s\", \"%s\") = %zu\n", s, reject,
	 strcspn(s, reject));
  puts("==> [STRCSPN] End");
}

void		strlen_test()
{
  size_t	i;
  char		*s[] =
    {
      "haha",
      "",
      "abcdefghijklmnopqrstuvwxyz",
      NULL
    };

  puts("==> [STRLEN] Start");
  for (i = 0; s[i] != NULL; i++)
    printf("-> strlen(\"%s\") = %i\n", s[i], strlen(s[i]));
  puts("==> [STRLEN] End");
}

void		strncmp_test()
{
  size_t	i;
  size_t	j;
  size_t	n;
  const char	*s[] =
    {
      "amen",
      "AMeN",
      "amen!",
      "AMeN!",
      "cctvvmb",
      NULL
    };

  puts("==> [STRNCMP] Start");
  for (i = 0; s[i] != NULL; ++i)
    for(j = 0; s[j] != NULL; ++j)
      {
	n = rand() % (strlen(s[i]) + 8);
	printf("-> strncmp(%s, %s, %zu) = %i\n", s[i], s[j], n,
	       strncmp(s[i], s[j], n));
      }
  puts("==> [STRNCMP] End");
}

void		strstr_test()
{
  size_t	i;
  size_t	j;
  char		*r;
  char		*s[] =
    {
      "abcdef",
      "abc",
      "def",
      "ghi"
      "",
      NULL
    };

  puts("==> [STRSTR] Start");
  for (i = 0; s[i] != NULL; i++)
    for (j = 0; s[j] != NULL; j++)
      {
	r = strstr(s[i], s[j]);
	printf("-> strstr(\"%s\", \"%s\") = \"%s\"\n",
	       s[i], s[j], (r == NULL ? "(nil)" : r));
      }
  puts("==> [STRSTR] End");
}

void		write_test()
{
  size_t	i;
  ssize_t	ret;
  char		*s[] =
    {
      "",
      "\n",
      "a\n",
      "ab\n",
      "abc\n",
      NULL
    };

  puts("==> [WRITE] Start");
  for (i = 0; s[i] != NULL; i++)
    printf("-> write(1, \"%s\", %zu) = %i\n",
	   s[i], strlen(s[i]),
	   write(1, s[i], strlen(s[i])));
  puts("-> ret = write(42, \"toto\", 4)");
  ret = write(42, "toto", 4);
  printf("bytes write : %u, ret == -1 ? %i\n", ret, ret == -1);
  perror("write");
  puts("==> [WRITE] End");
  errno = 0;
}

int		main()
{
  srand(23454);
  memcpy_test();
  memmove_test();
  memset_test();
  read_test();
  rindex_test();
  strcasecmp_test();
  strchr_test();
  strcmp_test();
  strcspn_test();
  strlen_test();
  strncmp_test();
  //strstr_test();
  write_test();
  return (0);
}
