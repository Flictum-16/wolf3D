/*
** my_is_alnum.c for  in /home/bertra_v/rendu/Piscine_C_J11/lib/my
**
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
**
** Started on  Mon Oct 20 14:34:47 2014 Bertrand Florent
** Last update Tue Oct 21 00:04:24 2014 Bertrand Florent
*/

int	my_is_alnum(char c)
{
  if ((c < '0' || c > '9') && (c < 'A' || c > 'Z') &&
      (c < 'a' || c > 'z'))
    return (0);
  return (1);
}
