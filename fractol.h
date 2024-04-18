#ifndef FARCTOL_H
# define FRACTOL_H

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
}				t_vars;

#define BLACK 0x000000
#define WIDTH 1080
#define HEIGHT 720

void	fractal_init(t_vars *vars, float width, float height);
void	fractal_render(t_vars *vars, float width, float height);
void	ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	interations(t_complex z, t_complex c);
void put_my_px(t_data *img, int width, int height, int value);
void	quadrants_fill(t_data *img, float width, float height);
#endif
