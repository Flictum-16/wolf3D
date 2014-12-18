/*
** my_strncpy.c for  in /home/bertra_v/rendu/Piscine_C_J06
**
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
**
** Started on  Mon Oct  6 11:07:11 2014 Bertrand Florent
** Last update Sun Nov 23 14:52:52 2014 Florent Bertrand
*/

char *my_strncpy(char *dest, char *src, int n)
{
  int   i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  if (i == n)
      dest[i] = '\0';
  return (dest);
}
