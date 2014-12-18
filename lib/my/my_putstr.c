/*
** my_putstr.c for  in /home/bertra_v/rendu/Piscine_C_J04
** 
** Made by Bertrand Florent
** Login   <bertra_v@epitech.net>
** 
** Started on  Thu Oct  2 12:26:24 2014 Bertrand Florent
** Last update Thu Oct  2 13:21:52 2014 Bertrand Florent
*/

int	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str++;
    }
}
