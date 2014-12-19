/*
** wolf3D.c for  in /home/bertra_v/tek_1/IGraph/MUL_2014_wolf3d
**
** Made by Florent Bertrand
** Login   <bertra_v@epitech.net>
**
** Started on  Tue Dec 16 20:51:02 2014 Florent Bertrand
** Last update Fri Dec 19 18:52:17 2014 Florent Bertrand
*/

#include <stdlib.h>
#include <math.h>
#include <X11/XKBlib.h>
#include <mlx_int.h>
#include "my.h"
#include "mlx.h"
#include "wolf3D.h"

int	map[9][9]=
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

int	key_hook(int keycode, t_mlx *mlx)
{
  printf("%d\n", keycode);
  if (keycode == 65307)
    exit(0);
  if (keycode == 65362 &&
      map[(int)(mlx->params->Xo + cos(mlx->params->angle))]
      [(int)(mlx->params->Yo + sin(mlx->params->angle))] == 0)
    {
      mlx->params->Xo += cos(mlx->params->angle) * 0.3;
      mlx->params->Yo += sin(mlx->params->angle) * 0.3;
      wolf_calc(mlx, mlx->params);
    }
  if (keycode == 65364 &&
      map[(int)(mlx->params->Xo - cos(mlx->params->angle) * 0.25)]
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
  if (keycode == 65362 &&
      map[(int)(mlx->params->Xo + cos(mlx->params->angle))]
      [(int)(mlx->params->Yo + sin(mlx->params->angle))] == 2)
    {
      my_putstr("Bravo, tu as trouvé la sortie du labyrinthe brave aventurier tu as le droit à un: Kinder");
      exit(3);
    }
  return (0);
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
      my_putstr("Don't touch my environnement !!!");
      return (0);
    }
  mlx.window = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Wolflictum3D");
  mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
  params.Xo = 4.5;
  params.Yo = 5.5;
  params.angle = M_PI / 4;
  mlx.params = &params;
  wolf_calc(&mlx, &params);
  mlx_expose_hook(mlx.window, expose_hook, &mlx);
  mlx_hook(mlx.window, KeyPress, KeyPressMask, key_hook, &mlx);
  mlx_loop(mlx.mlx);
}
