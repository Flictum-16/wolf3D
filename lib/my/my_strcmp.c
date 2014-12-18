/*
** my_strcmp.c for  in /home/bertra_v/rendu/Piscine_C_J06
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Mon Oct  6 17:49:15 2014 Bertrand Florent
** Last update Mon Oct  6 19:03:38 2014 Bertrand Florent
*/

int     my_strcmp(char *s1, char *s2)
{
  int   counter;

  counter = 0;
  while (s1[counter] == s2[counter] && s1[counter] != '\0')
    counter++;
  return (s1[counter] - s2[counter]);
}
