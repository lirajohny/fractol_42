#include "fractol.h"

int	test(int keycode, t_vars *vars)
{
	static float i = 0.8;
	static float j = 0.9;

	mlx_string_put(vars->mlx, vars->win, 1200 * i, 780 * j, 0xFFFFFF, "que se foda-se");
//	mlx_destroy_window(vars->mlx, vars->win);
	i -= 0.1;
	j -= 0.1;
	if (i == 0.1 || j == 0.1)
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
	while (i <= 360)
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
	int pallet[6] = {0x00FF00, 0x00FF80,0x00FFFF, 0x0080FF, 0x0000FF, 0x7F00FF};
	//int pallet[6] = {LIGHT_BLUE, RED, STEEL_BLUE, DARK_BLUE, CYAN, CORNFLOWER_BLUE};
	if (value >= 360)
		my_mlx_pixel_put(img, width, height, BLACK);
	else
	{
		int rgb = pallet[(value / 5) % 6];
		int red = (rgb >> 16) & 0xFF;  
		int green = (rgb >> 8) & 0xFF;
		int blue = rgb & 0xFF;       
		if ((value / 5) % 6 == 0)
			blue += 24 * (value % 5);
		else if ((value / 5) % 6 == 1)
			blue += 24 * (value % 5);
		else if ((value / 5) % 6 == 2)
			green -= 24 * (value % 5);
		else if ((value / 5) % 6 == 3)
			green -= 24 * (value % 5);
		else if ((value / 5) % 6 == 4)
			red += 24 * (value % 5) ;
		else if ((value / 5) % 6 == 5)
			red += 24 * (value % 5);
		int new_rgb = (red << 16) | (green << 8) | blue;
		my_mlx_pixel_put(img, width, height, new_rgb);
	}
}

void	fractal_init(t_vars *vars, float width, float height)
{
		vars->mlx = mlx_init();
		vars->win = mlx_new_window(vars->mlx, width, height, "Hello world!");
}
void	fractal_render(t_vars *vars, float width, float height)
{
		vars->img.img = mlx_new_image(vars->mlx, width, height);
		vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,&vars->img.endian);
		quadrants_fill(&vars->img, width, height);
		//change_colors(&img, width, height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
		mlx_key_hook(vars->win, test, &vars);
}

int	main (int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10) ||  ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		t_vars	vars;
		float	width = 1200;
		float height = 780;

		fractal_init(&vars, width, height);
		fractal_render(&vars, width, height);
		mlx_loop(vars.mlx);
		free(vars.mlx);
		free(vars.win);
	}
	else
	{
		ft_putstr_fd("error message\n", STDERR_FILENO);
		return -1;
	}
}
