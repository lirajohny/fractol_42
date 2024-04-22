#ifndef FARCTOL_H
# define FRACTOL_H

# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h> //debugg

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float	scale_x;
	float	scale_y;
	double	shift_x;
	double	shift_y;
}				t_data;

typedef	struct s_complex
{
	float	real;
	float	i;
}	t_complex;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	char	*name;
	double	julia_x;
	double	julia_y;
}	t_vars;

typedef	struct s_fill
{
	t_complex	z;
	t_complex	c;
	int			width;
	int			height;
}	t_fill;

#define BLACK 0x000000
#define WIDTH 800
#define HEIGHT 700

void	fractal_init(t_vars *vars, float width, float height);
void	fractal_render(t_vars *vars, float width, float height);
int	key_handler(int keysym,t_vars *vars);
void	events_init(t_vars *vars);
void	ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	interations(t_vars *vars, t_complex z, t_complex c);
void put_my_px(t_data *img, int width, int height, int value);
void	quadrants_fill(t_vars *vars, t_data *img, float width, float height);
void 	init_data(t_vars *vars, float width, float height);
int	close_handler(t_vars *vars);
int	mouse_handler(int button, int x, int y, t_vars *vars);
double	atodbl(char *s);
#endif
