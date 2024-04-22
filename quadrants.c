/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:38:37 by jlira             #+#    #+#             */
/*   Updated: 2024/04/22 10:42:55 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static void	quadrants(t_vars *vars, t_data *img, int i, int j)
{
	t_fill	val;
	int		nbr;

	val = vars->value;
	if (ft_strncmp("julia", vars->name, 5) == 0)
	{
		val.c.i = vars->julia_y;
		val.c.real = vars->julia_x;
		val.z.real = (j - (WIDTH / img->shift_x)) * val.real_x;
		if (i <= 0 && i < HEIGHT / img->shift_y)
			val.z.i = ((img->scale_y / img->shift_y) - (i * val.imaginary_y));
		else
			val.z.i = ((HEIGHT / img->shift_y) - i) * val.imaginary_y;
	}
	else
	{
		val.c.real = (j - (WIDTH / img->shift_x)) * val.real_x;
		if (i <= 0 && i < HEIGHT / img->shift_y)
			val.c.i = ((img->scale_y / img->shift_y) - (i * val.imaginary_y));
		else
			val.c.i = ((HEIGHT / img->shift_y) - i) * val.imaginary_y;
	}
	nbr = interations(vars, val.z, val.c);
	put_my_px(img, j, i, nbr);
}

void	init_data(t_vars *vars)
{
	vars->img.scale_x = 3.0;
	vars->img.scale_y = 2.5;
	vars->img.shift_x = 2.0;
	vars->img.shift_y = 2.0;
}

void	quadrants_fill(t_vars *vars, t_data *img)
{
	int	i;
	int	j;

	vars->value.z.i = 0;
	vars->value.z.real = 0;
	vars->value.c.i = 0;
	vars->value.c.real = 0;
	vars->value.real_x = (vars->img.scale_x) / WIDTH;
	vars->value.imaginary_y = (vars->img.scale_y) / HEIGHT;
	i = 0;
	while (i++ < HEIGHT)
	{
		j = 0;
		while (j++ < WIDTH)
			quadrants(vars, img, i, j);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	fractal_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		msg_malloc_err();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, vars->name);
	if (vars->win == NULL)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		msg_malloc_err();
	}
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (vars->win == NULL)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		msg_malloc_err();
	}
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	events_init(vars);
	init_data(vars);
}

void	fractal_render(t_vars *vars)
{
	quadrants_fill(vars, &vars->img);
}
