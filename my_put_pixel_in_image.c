/*
** my_put_pixel_in_image.c for  in /home/bertra_v/tek_1/Igraph/MUL_2014_fdf
**
** Made by Florent Bertrand
** Login   <bertra_v@epitech.net>
**
** Started on  Fri Nov 14 09:32:27 2014 Florent Bertrand
** Last update Sun Dec 21 16:42:04 2014 Florent Bertrand
*/

#include <stdio.h>
#include "mlx.h"
#include "wolf3D.h"

int	my_put_pixel_in_image(t_mlx *mlx, int x, int y, int color)
{
  int	bpp;
  int	sizeline;
  int	endian;
  int	*data;

  if (y < HEIGHT && y >= 0 && x >= 0 && x < WIDTH)
    {
      data = (int *)mlx_get_data_addr(mlx->img, &bpp, &sizeline, &endian);
      data[WIDTH * y + x] = color;
    }
  else
    return (0);
}

char	*strlcpy(char *dest, char *src, int n)
{
  int   i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  if (i == n)
      dest[i] = '\0';
  return (dest);
}
