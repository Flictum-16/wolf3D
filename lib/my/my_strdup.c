/*
** my_strdup.c for  in /home/bertra_v/rendu/Piscine_C_J08/ex_01
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Wed Oct  8 09:36:24 2014 Bertrand Florent
** Last update Wed Oct  8 12:30:31 2014 Bertrand Florent
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  char	*final;

  final= malloc(my_strlen(src) + 1);
  my_strcpy(final, src);
  return (final);
}
