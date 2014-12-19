/*
** utils.c for  in /home/bertra_v/tek_1/IGraph/MUL_2014_wolf3d
**
** Made by Florent Bertrand
** Login   <bertra_v@epitech.net>
**
** Started on  Fri Dec 19 18:51:31 2014 Florent Bertrand
** Last update Fri Dec 19 19:02:03 2014 Florent Bertrand
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "mlx.h"
#include "wolf3D.h"

int	map2[9][9]=
  {
    {1, 2, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1}
  };

void	clear_img(t_mlx *mlx, t_params *params)
{
  int	x;
  int   y;

  y = 0;
  x = 0;
  while (x < WIDTH)
    {
      y = 0;
      while (y < HEIGHT / 2)
	{
	  my_put_pixel_in_image(mlx, x, y, 0xADD8E6);
	  y++;
	}
      while (y < HEIGHT)
	{
	  my_put_pixel_in_image(mlx, x, y, 0x66cc66);
	  y++;
	}

      x++;
    }
}

void		d_wall(t_params *params, t_mlx *mlx, double pMx, double pMy)
{
  double	DP;
  double	DX;
  double	DY;
  double	height;


  DX = params->Xo + pMx;
  DY = params->Yo + pMy;
  while (map2[(int)DX][(int)DY] == 0)
    {
      DX += pMx * 0.001;
      DY += pMy * 0.001;
    }
  DP = sqrt(pow((params->Xo - DX), 2) + pow((params->Yo - DY), 2));
  DP /= sqrt(pow(pMx, 2) + pow(pMy, 2));
  height = WIDTH / (DP / 1);
  params->s_wall = WIDTH / 2 - height / 2;
  params->e_wall = params->s_wall + height;
  if (map2[(int)DX][(int)DY] == 1)
    {
      while (params->s_wall <= params->e_wall)
	my_put_pixel_in_image(mlx, params->j, params->s_wall++, 0x9E9E9E);
    }
  else if (map2[(int)DX][(int)DY] == 2)
    while (params->s_wall <= params->e_wall)
      my_put_pixel_in_image(mlx, params->j, params->s_wall++, 0xFF0000);
}

void		wolf_calc(t_mlx *mlx, t_params *params)
{
  int		i;
  int		Mx;
  double	pMx;
  double	My;
  double	pMy;

  i = 0;
  Mx = 1;
  clear_img(mlx, params);
  while (i <= WIDTH)
    {
      My = (WIDTH / 2.f - i) / WIDTH;
      pMx = Mx * cos(params->angle) - My * sin(params->angle);
      pMy = Mx * sin(params->angle) + My * cos(params->angle);
      params->j = i;
      d_wall(params, mlx, pMx, pMy);
      i++;
    }
  if (mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0) == 0)
    return ;
}