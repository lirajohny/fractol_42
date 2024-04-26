/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:34:08 by jlira             #+#    #+#             */
/*   Updated: 2024/04/25 17:49:36 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

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
		vars->img.shift_x += 0.1;
	else if (keysym == XK_Right)
		vars->img.shift_x -= 0.1;
	else if (keysym == XK_Up)
		vars->img.shift_y += 0.5;
	else if (keysym == XK_Down)
		vars->img.shift_y -= 0.5;
	else if (keysym == XK_0)
		vars->img.max_iterations += 1;
	quadrants_fill(vars, &vars->img);
	return (1);
}

#include <stdio.h>
int	mouse_handler(int button, int x, int y, t_vars *vars)
{
	printf("x is %i, y is %i\n", x, y);
	if (button == 5)
	{
		vars->img.scale_y *= 0.95;
		vars->img.scale_x *= 0.95;
		vars->img.shift_x += x * (WIDTH / vars->img.scale_x);
		vars->img.shift_y += y * (HEIGHT / vars->img.scale_y);
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
