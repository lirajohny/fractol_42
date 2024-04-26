/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:37:08 by jlira             #+#    #+#             */
/*   Updated: 2024/04/26 11:48:14 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

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
	int		max_iterations;
}				t_data;

typedef	struct s_complex
{
	float	real;
	float	i;
}	t_complex;

typedef	struct s_fill
{
	t_complex	z;
	t_complex	c;
	int			width;
	int			height;
	float		real_x;
	float		imaginary_y;
}	t_fill;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	char	*name;
	double	julia_x;
	double	julia_y;
	t_fill	value;
}	t_vars;

typedef	struct	s_colors
{
	int	pallet[6];
	int	rgb;
	int	red;
	int	green;
	int	blue;
	int	new_rgb;
}	t_colors;

#define BLACK 0x000000
#define WIDTH 500
#define HEIGHT 400
#define MAX_ITERATIONS 31
#define C1 0xFF0000
#define C2 0xFFFF00
#define C3 0x00FF00
#define C4 0x00FFFF
#define C5 0x0000FF
#define C6 0xFF00FF

void	fractal_init(t_vars *vars);
void	fractal_render(t_vars *vars);
int		key_handler(int keysym,t_vars *vars);
void	events_init(t_vars *vars);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		interations(t_vars *vars, t_complex z, t_complex c);
void	put_my_px(t_data *img, int j, int i, int value);
void	quadrants_fill(t_vars *vars, t_data *img);
void 	init_data(t_vars *vars);
int		close_win(t_vars *vars);
int		mouse_handler(int button, int x, int y, t_vars *vars);
double	atodbl(char *s);
int		check(char **av, int ac);
void	msg_malloc_err(void);
#endif
