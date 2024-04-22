#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	interations(t_vars *vars, t_complex z, t_complex c)
{
	double	tmp_real;
	int value;
	int iter;

	iter = 0;
	if (ft_strncmp("julia", vars->name, 5) == 0)
	{
		c.i = vars->julia_y;
		c.real = vars->julia_x;
	}
	else
	{
		z.i = 0;
		z.real = 0;
	}
	while (iter <= 360)
	{
		tmp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_real;
		z.real += c.real;
		z.i += c.i;
		value = iter;
		if (((z.real * z.real) + (z.i * z.i)) >=  4)
			return value;
		iter++;
	}
	return value;
}


void put_my_px(t_data *img, int width, int height, int value)
{
	int pallet[6] = {0x00FF00, 0x00FF80,0x00FFFF, 0x0080FF, 0x0000FF, 0x7F00FF};
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
static void	msg_malloc_err(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void	fractal_init(t_vars *vars, float width, float height)
{
		vars->mlx = mlx_init();
		if (vars->mlx == NULL)
			msg_malloc_err();
		vars->win = mlx_new_window(vars->mlx, width, height, vars->name);
		if (vars->win == NULL)
		{
			mlx_destroy_display(vars->mlx);
			free(vars->mlx);
			msg_malloc_err();
		}
		vars->img.img = mlx_new_image(vars->mlx, width, height);
		if (vars->win == NULL)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			free(vars->mlx);
			msg_malloc_err();
		}
		vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,&vars->img.endian);
		events_init(vars);
		init_data(vars, width, height);
}
void	fractal_render(t_vars *vars, float width, float height)
{
		quadrants_fill(vars, &vars->img, width, height);
}

int	main (int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10) ||  ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		t_vars	vars;
		
		vars.name = av[1];
		if (ac == 4)
		{
			vars.julia_x = atodbl(av[2]);
			vars.julia_y = atodbl(av[3]);
		}
		fractal_init(&vars, WIDTH, HEIGHT);
		fractal_render(&vars, WIDTH, HEIGHT);
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
