/*
** my_strupcase.c for  in /home/bertra_v/rendu/Piscine_C_J06
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Tue Oct  7 13:28:52 2014 Bertrand Florent
** Last update Wed Oct  8 16:22:38 2014 Bertrand Florent
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
        {
	  str[i] = str[i] - ('a' - 'A');
	}
      i++;
    }
  return (str);
}
