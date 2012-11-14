/*
** my_color.h for color in /home/rabier_p/work/PROJ/C/MINISHELL1
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Sun Jan 10 14:08:45 2010 patrick rabier
** Last update Sun Jan 10 14:11:28 2010 patrick rabier
*/

#ifndef COLOR
# define COLOR

static const char GREEN[] = {27, '[', '0', '1', ';', '3', '2', 'm', 0};
static const char WHITE[] = {27, '[', 'm', 0};
static const char PURPLE[] = {27, '[', '0', '1', ';', '3', '4', 'm', 0};
static const char RED[] = {27, '[', '0', '1', ';', '3', '1', 'm', 0};
static const char CYAN[] = {27, '[', '0', '1', ';', '3', '6', 'm', 0};
static const char YELLOW[] = {27, '[', '0', '1', ';', '3', '3', 'm', 0};

#endif
