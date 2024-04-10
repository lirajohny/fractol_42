#include "fractol.h"

int	close(int keycode, t_vars *vars)
{
	static float i = 0.8;
	static float j = 0.9;

	mlx_string_put(vars->mlx, vars->win, 600 * i, 600 * j, 0xFFFFFF, "words");
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

void put_my_px(t_data *img, int width, int height, int value)
{
	int pallet[6] = {0x00FF00, 0x00FF80,0x00FFFF, 0x0080FF, 0x0000FF, 0x7F00FF};
	if (value >= 360)
		my_mlx_pixel_put(img, width, height, BLACK);
	else
	{
		int rgb = pallet[(value / 10) % 6];
		int red = (rgb >> 16) & 0xFF;   // Componente Vermelho (R)
		int green = (rgb >> 8) & 0xFF;  // Componente Verde (G)
		int blue = rgb & 0xFF;          // Componente Azul (B)
		if ((value / 10) % 6 == 0)
			blue += 12 * (value / 10) % 10;
		else if ((value / 10) % 6 == 1)
			blue += 12 * (value % 10) % 10;
		else if ((value / 10) % 6 == 2)
			green -= 12 * (value % 10) % 10;
		else if ((value / 10) % 6 == 3)
			green -= 12 * (value % 10) % 10;
		else if ((value / 10) % 6 == 4)
			red += 12 * (value % 10) % 10;
		else if ((value / 10) % 6 == 5)
			red += 12 * (value % 10) % 10;
		int new_rgb = (red << 16) | (green << 8) | blue;
		my_mlx_pixel_put(img, width, height, new_rgb);
	}
}

int	main (void)
{
	t_vars	vars;
	float	width = 600;
	float height = 600;
	t_data img;
	//1449x900

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "Hello world!");
	img.img = mlx_new_image(vars.mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	int value = 0;
	int i = 0;
	int j = 0;
	while (i < 600)
	{
		j = 0;
		value = 0;
		while (j < 600)
		{
			put_my_px(&img, j, i, value);
			j++;
			value++;
		}
		i++;
	}
	/*
	for (int i = 0; i < 32; i++)
	{
		int j = 320;
		put_my_px(&img, j, i, 0xFFFFFF);
	}*/

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, close, &vars);
	mlx_loop(vars.mlx);
	free(vars.mlx);
	free(vars.win);
}
