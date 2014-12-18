/*
** my_revstr.c for  in /home/bertra_v/rendu/Piscine_C_J06/ex_03
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Mon Oct  6 14:44:58 2014 Bertrand Florent
** Last update Mon Oct  6 16:07:03 2014 Bertrand Florent
*/

char    *my_revstr(char *str)
{
  int   swap;
  int   counter;
  int   tmp;

  swap = 0;
  counter = 0;
  tmp = 0;
  if (str != 0)
    {
      while (str[counter] != '\0')
	counter++;
      counter--;
      while (swap < counter)
	{
	  tmp = str[swap];
	  str[swap] = str[counter];
	  str[counter] = tmp;
	  swap++;
	  counter--;
	}
      return (str);
    }
  return (0);
}
