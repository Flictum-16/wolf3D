/*
** my_swap.c for  in /home/bertra_v/rendu/Piscine_C_J04
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Thu Oct  2 10:30:20 2014 Bertrand Florent
** Last update Thu Oct  2 10:39:03 2014 Bertrand Florent
*/

int	my_swap(int *a, int *b)
{
  int	ct;

  ct = *a;
  *a = *b;
  *b = ct;
}
