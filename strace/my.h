/*
** my.h for my.h in /home/krik/work/strace_unix/
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Wed May 25 20:08:12 2011 patrick rabier
** Last update Wed May 25 20:08:15 2011 Patrick Rabier
*/

#ifndef   	__MY_H__
# define   	__MY_H__

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <errno.h>
#include <sys/user.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int		is_numeric(const char *s);

#endif 	    /* !__MY_H__ */
