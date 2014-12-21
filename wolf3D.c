/*
** wolf3D.c for  in /home/bertra_v/tek_1/IGraph/MUL_2014_wolf3d
**
** Made by Florent Bertrand
** Login   <bertra_v@epitech.net>
**
** Started on  Tue Dec 16 20:51:02 2014 Florent Bertrand
** Last update Sun Dec 21 17:08:00 2014 Florent Bertrand
*/

#include <stdlib.h>
#include <math.h>
#include <X11/XKBlib.h>
#include "my.h"
#include "mlx.h"
#include "wolf3D.h"
#include "map.h"

int	key_hook(int keycode, t_mlx *mlx)
{
  if (keycode == 65307)
    exit(0);
  if (keycode == 65362 &&
      map[mlx->niv][(int)(mlx->params->Xo + cos(mlx->params->angle))]
      [(int)(mlx->params->Yo + sin(mlx->params->angle))] == 0)
    {
      mlx->params->Xo += cos(mlx->params->angle) * 0.3;
      mlx->params->Yo += sin(mlx->params->angle) * 0.3;
      wolf_calc(mlx, mlx->params);
    }
  if (keycode == 65364 &&
      map[mlx->niv][(int)(mlx->params->Xo - cos(mlx->params->angle) * 0.25)]
      [(int)(mlx->params->Yo - sin(mlx->params->angle) * 0.25)] == 0)
    {
      mlx->params->Xo -= cos(mlx->params->angle) * 0.1;
      mlx->params->Yo -= sin(mlx->params->angle) * 0.1;
      wolf_calc(mlx, mlx->params);
    }
  key_hook2(keycode, mlx);
  return (0);
}

int	key_hook2(int keycode, t_mlx *mlx)
{
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
  if (keycode == 65470)
      XkbSetAutoRepeatRate(((t_xvar*)mlx->mlx)->display, XkbUseCoreKbd,
                           REFRESH_OPTION, REFRESH_OPTION);
  if (keycode == 65471)
    XkbSetAutoRepeatRate(((t_xvar*)mlx->mlx)->display, XkbUseCoreKbd,
			 660, 40);
  key_hook3(keycode, mlx);
  return (0);
}

int	key_hook3(int keycode, t_mlx *mlx)
{
  if (keycode == 65362 &&
      map[mlx->niv][(int)(mlx->params->Xo + cos(mlx->params->angle))]
      [(int)(mlx->params->Yo + sin(mlx->params->angle))] == 2)
    {
      mlx->niv++;
      wolf_calc(mlx, mlx->params);
    }
  if (keycode == 65362 &&
      map[mlx->niv][(int)(mlx->params->Xo + cos(mlx->params->angle))]
      [(int)(mlx->params->Yo + sin(mlx->params->angle))] == 3)
    {
      mlx->niv++;
      wolf_calc(mlx, mlx->params);
    }
  if (keycode == 65362 &&
      map[mlx->niv][(int)(mlx->params->Xo + cos(mlx->params->angle))]
      [(int)(mlx->params->Yo + sin(mlx->params->angle))] == 4)
    {
      my_putstr("Bravo, tu as trouvé la sortie du labyrinthe ");
      my_putstr("brave aventurier tu as le droit à un: Kinder");
      exit(3);
    }
  return (0);
}

void	expose_hook(t_mlx *mlx)
{
  mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
  mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->gun,
			  (WIDTH - (2 * mlx->gun->width)),
			  (HEIGHT - (mlx->gun->height)));
}

int	main(int ac, char **av)
{
  t_params	params;
  t_mlx		mlx;

  mlx.niv = 0;
  if ((mlx.mlx = mlx_init()) == NULL)
    {
      my_putstr("Don't touch my environnement !!!");
      return (0);
    }
  mlx.window = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Wolflictum3D");
  mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
  mlx.gun = mlx_xpm_file_to_image(mlx.mlx, "gun.xpm", &mlx.gx, &mlx.gy);
  params.Xo = 1.5;
  params.Yo = 1.5;
  params.angle = M_PI / 4;
  mlx.params = &params;
  wolf_calc(&mlx, &params);
  mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.gun,
			  (WIDTH - (2 * mlx.gun->width)),
			  (HEIGHT - (mlx.gun->height)));
  mlx_expose_hook(mlx.window, expose_hook, &mlx);
  mlx_hook(mlx.window, KeyPress, KeyPressMask, key_hook, &mlx);
  mlx_loop(mlx.mlx);
  return (0);
}
