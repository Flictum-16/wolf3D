/*
** my_power_rec.c for  in /home/bertra_v/rendu/Piscine_C_J05
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Sat Oct  4 00:55:50 2014 Bertrand Florent
** Last update Wed Oct  8 16:22:56 2014 Bertrand Florent
*/

int	my_power_rec(int nb, int power)
{
  int	result;

  if (power == 0)
    return (1);
  if (power < 0)
    return (0);
  while (power > 1)
    {
      result = my_power_rec(nb, power - 1) * nb;
      if (result < 0)
	return (0);
      return (result);
    }
  return (nb);
}
