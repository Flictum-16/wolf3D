/*
** my_strstr.c for  in /home/bertra_v/rendu/Piscine_C_J06
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Mon Oct  6 19:27:19 2014 Bertrand Florent
** Last update Mon Oct  6 23:22:46 2014 Bertrand Florent
*/

char	*my_strstr(char *str, char *to_find)
{
  int	counter;
  int	counter2;
  int	stock;

  counter = 0;
  counter2 = 0;
  stock = 0;
  while (str[counter] != '\0')
    {
      while (to_find[counter2] != '\0' && str[counter + counter] != '\0'
	     && str[counter + counter2] == to_find[counter2])
	counter2++;
      if (to_find[counter2] == '\0')
	return (&str[counter]);
      counter2 = 0;
      counter++;
    }
  return (0);
}
