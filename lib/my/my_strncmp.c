/*
** my_strncmp.c for  in /home/bertra_v/rendu/Piscine_C_J06
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Mon Oct  6 19:05:57 2014 Bertrand Florent
** Last update Wed Oct  8 16:22:05 2014 Bertrand Florent
*/

int     my_strncmp(char *s1, char *s2, int n)
{
  int	counter;

  counter = 0;
  while (counter < n && s1[counter] == s2[counter] && s1[counter] != '\0'
	 && s2[counter] != 0)
    counter++;
  if (counter == n)
    return (0);
  else
    return (s1[counter] - s2[counter]);
}
