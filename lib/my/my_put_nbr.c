/*
** my_put_nbr.c for  in /home/mougeo_s
**
** Made by Stessy MOUGEOT
** Login   <mougeo_s@epitech.net>
**
** Started on  Mon Oct  6 20:03:06 2014 Stessy MOUGEOT
** Last update Mon Oct 20 20:52:18 2014 Bertrand Florent
*/

int	my_put_nbr_1(int nb)
{
  if (nb >= 10 || nb <= -10)
    my_put_nbr_1(nb / 10);
  if (nb >= 0)
    my_putchar(nb % 10 + '0');
  else
    my_putchar(-nb % 10 + '0');
}

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
    }
  my_put_nbr_1(nb);
}
