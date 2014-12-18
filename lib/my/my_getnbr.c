/*
** my_getnbr.c for  in /home/bertra_v/rendu/Piscine_C_J11/lib/my
**
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
**
** Started on  Mon Oct 20 19:23:15 2014 Bertrand Florent
** Last update Mon Oct 20 19:23:20 2014 Bertrand Florent
*/

int	my_getnbr(char *str)
{
  int	i;
  int	sign;
  int	nbr;
  int	test;

  i = 0;
  nbr = 0;
  sign = 1;
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	sign *= -1;
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      test = nbr;
      if (str[i] >= '0' && str[i] <= '9')
	nbr = (nbr * 10) + ((str[i] - '0') * sign);
      i++;
      if (test != nbr / 10)
	return (0);
    }
  return (nbr);
}
