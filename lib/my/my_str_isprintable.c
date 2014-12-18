/*
** my_str_isprintable.c for  in /home/bertra_v/rendu/Piscine_C_J06
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Tue Oct  7 19:35:06 2014 Bertrand Florent
** Last update Tue Oct  7 19:36:02 2014 Bertrand Florent
*/
int     my_str_isprintable(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 32  && str[i] <= 126))
        return (0);
      i++;
    }
  return (1);
}

