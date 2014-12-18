/*
** wolf3D.h for  in /home/bertra_v/tek_1/IGraph/MUL_2014_wolf3d
**
** Made by Florent Bertrand
** Login   <bertra_v@epitech.net>
**
** Started on  Tue Dec 16 18:02:10 2014 Florent Bertrand
** Last update Thu Dec 18 22:13:54 2014 Florent Bertrand
*/

#ifndef WOLF3D_
 # define WOLF3D_

#define REFRESH_OPTION

#define WIDTH 1200

#define HEIGHT 1100

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
  t_params	*params;
}		t_mlx;

int    my_put_pixel_in_image(t_mlx *mlx, int x, int y, int color);

#endif /*WOLF3D_*/
