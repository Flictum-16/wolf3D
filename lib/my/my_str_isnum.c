/*
** my_str_isnum.c for  in /home/bertra_v/rendu/Piscine_C_J06
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Tue Oct  7 18:17:36 2014 Bertrand Florent
** Last update Tue Oct  7 19:29:24 2014 Bertrand Florent
*/

int	my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
        return (0);
      i++;
    }
  return (1);
}
