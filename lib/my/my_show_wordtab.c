/*
** my_show_wordtab.c for  in /home/bertra_v/rendu/Piscine_C_J11/lib/my
**
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
**
** Started on  Mon Oct 20 21:05:13 2014 Bertrand Florent
** Last update Mon Oct 20 21:41:55 2014 Bertrand Florent
*/

void	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}
