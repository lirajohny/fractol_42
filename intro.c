/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:17:01 by jlira             #+#    #+#             */
/*   Updated: 2024/04/22 11:06:36 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	interations(t_vars *vars, t_complex z, t_complex c)
{
	double	tmp_real;
	int		value;
	int		iter;

	iter = 0;
	vars->img.max_iterations = MAX_ITERATIONS;
	if (ft_strncmp("julia", vars->name, 5) == 0)
	{
		c.i = vars->julia_y;
		c.real = vars->julia_x;
	}
	while (iter <= vars->img.max_iterations)
	{
		tmp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_real;
		z.real += c.real;
		z.i += c.i;
		value = iter;
		if (((z.real * z.real) + (z.i * z.i)) >= 4)
			return (value);
		iter++;
	}
	return (value);
}

int	main (int ac, char **av)
{
	t_vars	vars;

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)
		|| ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		vars.name = av[1];
		if (ac == 4)
		{
			vars.julia_x = atodbl(av[2]);
			vars.julia_y = atodbl(av[3]);
		}
		fractal_init(&vars);
		fractal_render(&vars);
		mlx_loop(vars.mlx);
		free(vars.mlx);
		free(vars.win);
	}
	else
	{
		ft_putstr_fd("error message\n", STDERR_FILENO);
		return (-1);
	}
}
