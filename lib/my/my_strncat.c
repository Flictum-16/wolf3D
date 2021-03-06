/*
** my_strncat.c for  in /home/bertra_v/rendu/Piscine_C_J07/exo_01
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Tue Oct  7 17:07:12 2014 Bertrand Florent
** Last update Tue Oct  7 17:10:44 2014 Bertrand Florent
*/

char    *my_strncat(char *dest, char *src, int nb)
{
  int   counter_a;
  int   counter_b;

  counter_a = 0;
  counter_b = 0;
  while (dest[counter_a] != '\0')
    {
      counter_a++;
    }
  while (counter_b < nb)
    {
      dest[counter_a] = src[counter_b];
      counter_a++;
      counter_b++;
    }
  dest[counter_a] = '\0';
  return (dest);
}
