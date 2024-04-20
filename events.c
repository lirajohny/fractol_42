#include "fractol.h"

int	key_handler(int keysym,t_vars *vars)
{
//	if (keysym == XK_Escape)
//		close_handler(vars);
	if (keysym == XK_Left)
		vars->img.shift_x += 0.1;
	else if (keysym == XK_Right)
		vars->img.shift_x -= 0.1;
	else if (keysym == XK_Up)
	{
		printf("up\n");
		vars->img.shift_y += 0.5;
	}
	else if (keysym == XK_Down)
	{
		printf("down\n");
		vars->img.shift_y -= 0.5;
	}
	else if (keysym == XK_0) //zoom
	{
		vars->img.scale_y -= 0.5;
		vars->img.scale_x -= 0.5;
	}
	else if (keysym == XK_minus) //zoom
	{
		vars->img.scale_y += 0.5;
		vars->img.scale_x += 0.5;
	}
	quadrants_fill(vars, &vars->img, WIDTH, HEIGHT);
}


void	events_init(t_vars *vars)
{
	mlx_hook(vars->win, KeyPress, KeyPressMask, key_handler, vars);
	//mlx_hook(vars->win, ButtonPress, ButtonPressMask, mouse_handler, vars);
	//mlx_hook(vars->win, DestroyNotify, StructureNotifyMask, close_handler, vars);
}
