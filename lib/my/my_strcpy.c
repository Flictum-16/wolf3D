/*
** my_strcpy.c for  in /home/bertra_v/rendu/Piscine_C_J06/ex_01
**
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
**
** Started on  Mon Oct  6 10:12:55 2014 Bertrand Florent
** Last update Wed Nov 19 16:21:11 2014 Florent Bertrand
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (src[i] != '\0')
    {
      dest[j] = src[i];
      i++;
      j++;
    }
  dest[j] = '\0';
  return (dest);
}
