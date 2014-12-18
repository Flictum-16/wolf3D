/*
** my_strlen.c for  in /home/bertra_v/Downloads
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Thu Oct  2 16:46:42 2014 Bertrand Florent
** Last update Thu Oct  2 17:10:49 2014 Bertrand Florent
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
