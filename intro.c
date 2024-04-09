#include "fractol.h"

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	interations(t_complex z, t_complex c)
{
	double	tmp_real;
	int value;
	int i = 0;
	z.real = 0;
	z.i = 0;
	while (i <= 47)
	{
		tmp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_real;
		z.real += c.real;
		z.i += c.i;
		value = i;
		if (((z.real * z.real) + (z.i * z.i)) >=  4)
			return value;
		i++;
	}
	return value;
}

void put_my_px(t_data *img, int width, int height, int value)
{
	if (value >= 47)
		my_mlx_pixel_put(img, width, height, BLACK);
	else if (value >= 22 && value < 25 || (value >= 43 && value < 47))
		my_mlx_pixel_put(img, width, height, MIDNIGHT_BLUE);
	else if (value >= 19 && value < 22 || (value >= 40 && value < 43))
		my_mlx_pixel_put(img, width, height, DARK_BLUE);
	else if (value >= 16 && value < 19 || (value >= 37 && value < 40))
		my_mlx_pixel_put(img, width, height, NAVY_BLUE);
	else if (value >= 13 && value < 16 || (value >= 34 && value < 37))
		my_mlx_pixel_put(img, width, height, ROYAL_BLUE);
	else if (value >= 10 && value < 13 || (value >= 31 && value < 34))
		my_mlx_pixel_put(img, width, height, STEEL_BLUE);
	else if (value >= 7 && value < 10 || (value >= 28  && value < 31))
		my_mlx_pixel_put(img, width, height, SKY_BLUE);
	else if (value >= 4 && value < 7 || (value >= 25 && value < 28))
		my_mlx_pixel_put(img, width, height, LIGHT_BLUE);
}

int	main (void)
{
	t_vars	vars;
	float	width = 1449;
	float height = 900;
	t_data img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "Hello world!");
	img.img = mlx_new_image(vars.mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);

	quadrants_fill(&img, width, height);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	//mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
	free(vars.mlx);
	free(vars.win);
}
