/*
** my_str_to_wordtab.c for  in /home/bertra_v/rendu/Piscine_C_J11/lib/my
**
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
**
** Started on  Mon Oct 20 14:34:11 2014 Bertrand Florent
** Last update Tue Oct 21 00:06:11 2014 Bertrand Florent
*/

#include <stdlib.h>

int	my_count_word(char *str)
{
  int	i;
  int	count;

  count = 0;
  i = 1;
  if (my_is_alnum(str[i]))
    count++;
  while (str[i] != '\0')
    {
      if (!my_is_alnum(str[i]) && my_is_alnum(str[i + 1]))
	count++;
      i++;
    }
  return (count);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	i;
  int	ptr;

  ptr = 0;
  tab = malloc(sizeof(char *) * (my_count_word(str) + 1));
  i = 0;
  if (my_is_alnum(str[0]))
    tab[ptr++] = str;
  while (str[i] != '\0')
    {
      if (!my_is_alnum(str[i]))
	{
	  str[i] = '\0';
	  if (my_is_alnum(str[i + 1]))
	    tab[ptr++] = &str[i + 1];
	}
      i++;
    }
  tab[ptr] = NULL;
  return (tab);
}
