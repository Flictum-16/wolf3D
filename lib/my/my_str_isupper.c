/*
** my_str_isupper.c for  in /home/bertra_v/rendu/Piscine_C_J06
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Tue Oct  7 19:30:28 2014 Bertrand Florent
** Last update Tue Oct  7 19:34:02 2014 Bertrand Florent
*/
int     my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 'A' && str[i] <= 'Z'))
        return (0);
      i++;
    }
  return (1);
}

