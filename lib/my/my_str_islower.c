/*
** my_str_islower.c for  in /home/bertra_v/rendu/Piscine_C_J06
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Tue Oct  7 19:27:41 2014 Bertrand Florent
** Last update Tue Oct  7 19:29:48 2014 Bertrand Florent
*/

int	my_str_islower(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 'a' && str[i] <= 'z'))
        return (0);
      i++;
    }
  return (1);
}
