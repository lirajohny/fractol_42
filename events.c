/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:34:08 by jlira             #+#    #+#             */
/*   Updated: 2024/04/26 11:23:29 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include <X11/X.h>

int	close_win(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
		close_win(vars);
	if (keysym == XK_Left)
		vars->img.shift_x *= 0.99;
	else if (keysym == XK_Right)
		vars->img.shift_x *= 1.01;
	else if (keysym == XK_Up)
		vars->img.shift_y *= 0.99;
	else if (keysym == XK_Down)
		vars->img.shift_y *= 1.01;
	else if (keysym == XK_0)
		vars->img.max_iterations += 1;
	quadrants_fill(vars, &vars->img);
	return (1);
}

int	julia_sets(int x, int y, t_vars *vars)
{
	if (ft_strncmp("julia", vars->name, 5) == 0)
	{
		if (x < WIDTH / 2)
			vars->julia_x = -1 * (x * (vars->img.scale_x / WIDTH));
		else
			vars->julia_x = x * (vars->img.scale_x / WIDTH);
		if (y <= HEIGHT / 2)
			vars->julia_y = y * (vars->img.scale_y / HEIGHT);
		else
			vars->julia_y = -1 * (y * (vars->img.scale_y / HEIGHT));
		quadrants_fill(vars, &vars->img);
	}
	return (1);
}

int	mouse_handler(int button, int x, int y, t_vars *vars)
{
	if (button == 5)
	{
		vars->img.scale_y *= 0.95;
		vars->img.scale_x *= 0.95;
	}
	else if (button == 4)
	{
		vars->img.scale_y *= 1.05;
		vars->img.scale_x *= 1.05;
	}
	quadrants_fill(vars, &vars->img);
	return (1);
}

void	events_init(t_vars *vars)
{
	mlx_hook(vars->win, KeyPress, KeyPressMask, key_handler, vars);
	mlx_hook(vars->win, ButtonPress, ButtonPressMask, mouse_handler, vars);
	mlx_hook(vars->win, DestroyNotify, StructureNotifyMask, close_win, vars);
}
