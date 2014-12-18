/*
** my_strcapitalize.c for  in /home/bertra_v/rendu/Piscine_C_J06/ex_09
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Tue Oct  7 15:00:07 2014 Bertrand Florent
** Last update Tue Oct  7 18:12:24 2014 Bertrand Florent
*/

int	my_is_al_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else if (c >= 'a' && c <= 'z')
    return (1);
  else if (c >= 'A' && c <= 'Z')
    return (1);
  else
    return (0);
}

char    *my_strcapitalize(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	{
	  if (i == 0 || !my_is_al_num(str[i - 1]))
	    str[i] = str[i] - ('a' - 'A');
	}
      i++;
    }
  return (str);
}
