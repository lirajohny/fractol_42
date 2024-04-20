#include "fractol.h"

static t_fill quadrants(t_data *img, int i, int j, t_fill value)
{
	float	real_x;
	float	imaginary_y;

	real_x = (img->scale_x) / value.width;
	imaginary_y = (img->scale_y) / value.height;
	value.c.real = (j - (value.width / img->shift_x)) * real_x;
	if (i <= 0 && i < value.height / img->shift_y) // I quadrant && VI quadrant
		value.c.i = ((img->scale_y / img->shift_y) - (i * imaginary_y));
	else // II qudrant && III quadrant
		value.c.i = ((value.height / img->shift_y) - i) * imaginary_y;
	int	nbr = interations(value.z, value.c);
	put_my_px(img, j, i, nbr);
	return (value);
}

void 	init_data(t_vars *vars, float width, float height)
{
	vars->img.scale_x = 3.0;
	vars->img.scale_y = 2.5;
	vars->img.shift_x = 1.51515152;
	vars->img.shift_y = 2.0;
	
}
void	quadrants_fill(t_vars *vars, t_data *img, float width, float height)
{
	int i;
	int	j;
	t_fill	value;

	value.z.i = 0;
	value.z.real = 0;
	value.c.i = 0;
	value.c.real = 0;
	value.height  = height;
	value.width = width;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			quadrants(img, i, j, value);
			j++;
		}
		value.z.i-=value.z.i;
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
