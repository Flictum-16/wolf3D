/*
** my_strlowcase.c for  in /home/bertra_v/rendu/Piscine_C_J06
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Tue Oct  7 14:43:51 2014 Bertrand Florent
** Last update Tue Oct  7 15:06:10 2014 Bertrand Florent
*/

char    *my_strlowcase(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
        {
          str[i] = str[i] + ('a' - 'z');
        }
      i++;
    }
  return (str);
}
