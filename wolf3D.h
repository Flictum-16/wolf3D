/*
** wolf3D.h for  in /home/bertra_v/tek_1/IGraph/MUL_2014_wolf3d
**
** Made by Florent Bertrand
** Login   <bertra_v@epitech.net>
**
** Started on  Tue Dec 16 18:02:10 2014 Florent Bertrand
** Last update Sat Dec 20 18:28:27 2014 Florent Bertrand
*/

#ifndef WOLF3D_
 # define WOLF3D_

#define REFRESH_OPTION 60

#define WIDTH 1200

#define HEIGHT (WIDTH * 9) / 16

#include <mlx_int.h>

typedef struct	s_params
{
  double	Xo;
  double	Yo;
  double	angle;
  int		Mx;
  int		calc;
  int		s_wall;
  int		e_wall;
  int		j;
}		t_params;

typedef	struct	s_mlx
{
  void		*mlx;
  void		*window;
  void		*img;
  t_img		*gun;
  t_params	*params;
  int		gx;
  int		gy;
}		t_mlx;

int	map[9][9];
int	my_put_pixel_in_image(t_mlx *mlx, int x, int y, int color);
void	wolf_calc(t_mlx *mlx, t_params *params);

#endif /*WOLF3D_*/
