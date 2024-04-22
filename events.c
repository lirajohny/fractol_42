#include "fractol.h"

int	close_handler(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym,t_vars *vars)
{
	if (keysym == XK_Escape)
		close_handler(vars);
	printf("%d\n", keysym);
	if (keysym == XK_Left)
		vars->img.shift_x += 0.1;
	else if (keysym == XK_Right)
		vars->img.shift_x -= 0.1;
	else if (keysym == XK_Up)
		vars->img.shift_y += 0.5;
	else if (keysym == XK_Down)
		vars->img.shift_y -= 0.5;
	else if (keysym == XK_0) //zoom
	{
		vars->img.scale_y *= 0.95;
		vars->img.scale_x *= 0.95;
	}
	else if (keysym == XK_minus) //zoom
	{
		vars->img.scale_y *= 1.05;
		vars->img.scale_x *= 1.05;
	}
	quadrants_fill(vars, &vars->img, WIDTH, HEIGHT);
}

int	mouse_handler(int button, int x, int y, t_vars *vars)
{
	printf("%d\n", button);
	if (button == 5)
	{
		vars->img.scale_y -= 0.5;
		vars->img.scale_x -= 0.5;
	}
	else if (button == 4)
	{
		vars->img.scale_y += 0.5;
		vars->img.scale_x += 0.5;
	}
	quadrants_fill(vars, &vars->img, WIDTH, HEIGHT);
}

void	events_init(t_vars *vars)
{
	mlx_hook(vars->win, KeyPress, KeyPressMask, key_handler, vars);
	mlx_hook(vars->win, ButtonPress, ButtonPressMask, mouse_handler, vars);
	mlx_hook(vars->win, DestroyNotify, StructureNotifyMask, close_handler, vars);
}
