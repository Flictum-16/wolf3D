/*
** wolf3D.c for  in /home/bertra_v/tek_1/IGraph/MUL_2014_wolf3d
**
** Made by Florent Bertrand
** Login   <bertra_v@epitech.net>
**
** Started on  Tue Dec 16 20:51:02 2014 Florent Bertrand
** Last update Thu Dec 18 23:01:37 2014 Florent Bertrand
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "mlx.h"
#include "wolf3D.h"

int	map[6][6]=
  {
    {1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 1},
    {1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
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
      while (y < HEIGHT)
	{
	  my_put_pixel_in_image(mlx, x, y, 0x00000000);
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
  while (map[(int)DX][(int)DY] != 1)
    {
      DX += pMx * 0.001;
      DY += pMy * 0.001;
    }
  DP = sqrt(pow((params->Xo - DX), 2) + pow((params->Yo - DY), 2));
  DP /= sqrt(pow(pMx, 2) + pow(pMy, 2));
  height = WIDTH / (DP / 1);
  params->s_wall = WIDTH / 2 - height / 2;
  params->e_wall = params->s_wall + height;
  while (params->s_wall <= params->e_wall)
    my_put_pixel_in_image(mlx, params->j, params->s_wall++, 0x9E9E9E);

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

int	key_hook(int keycode, t_mlx *mlx)
{
  printf("%d\n", keycode);
  if (keycode == 65307)
    exit(0);
  if (keycode == 65362 &&
      map[(int)(mlx->params->Xo + cos(mlx->params->angle))]
      [(int)(mlx->params->Yo + sin(mlx->params->angle))] != 1)
    {
      mlx->params->Xo += cos(mlx->params->angle) * 0.3;
      mlx->params->Yo += sin(mlx->params->angle) * 0.3;
      wolf_calc(mlx, mlx->params);
    }
  if (keycode == 65364 &&
      map[(int)(mlx->params->Xo - cos(mlx->params->angle) * 0.25)]
      [(int)(mlx->params->Yo - sin(mlx->params->angle) * 0.25)] != 1)
    {
      mlx->params->Xo -= cos(mlx->params->angle) * 0.1;
      mlx->params->Yo -= sin(mlx->params->angle) * 0.1;
      wolf_calc(mlx, mlx->params);
    }
  if (keycode == 65363)
    {
      mlx->params->angle -= 0.1;
      wolf_calc(mlx, mlx->params);
    }
  if (keycode == 65361)
    {
      mlx->params->angle += 0.1;
      wolf_calc(mlx, mlx->params);
    }
}

int	expose_hook(t_mlx *mlx)
{
  mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}

int	main(int ac, char **av)
{
  t_params	params;
  t_mlx		mlx;

  if ((mlx.mlx = mlx_init()) == NULL)
    {
      printf("Don't touch my environnement !!!");
      return (0);
    }
  mlx.window = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Wolflictum3D");
  mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
  params.Xo = 1.5;
  params.Yo = 1.5;
  params.angle = M_PI / 4;
  mlx.params = &params;
  wolf_calc(&mlx, &params);
  mlx_expose_hook(mlx.window, expose_hook, &mlx);
  mlx_key_hook(mlx.window, key_hook, &mlx);
  mlx_loop(mlx.mlx);
}
