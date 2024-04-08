#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef	struct s_complex
{
	float	real;
	float	i;
}	t_complex;

#define BLUE 0x0000FF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define YELLOW 0xFFFF00
#define CYAN 0x00FFFF
#define MAGENTA 0xFF00FF
#define BLACK 0x000000
#define LIGHT_BLUE 0xADD8E6
#define SKY_BLUE 0x87CEEB
#define STEEL_BLUE 0x4682B4
#define ROYAL_BLUE 0x4169E1
#define NAVY_BLUE 0x000080
#define DARK_BLUE 0x00008B
#define MIDNIGHT_BLUE 0x191970
#define CORNFLOWER_BLUE 0x6495ED

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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
	while (i < 90)
	{
		// z = zˆ2 + c;
		// printf("c is (%f + %fi)\n", c.real, c.i);
		// printf("Z(%i) : (%f + %fi)\n",i, c.real, c.i);
		tmp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_real;
		z.real += c.real;
		z.i += c.i;
		value = i;
		if (((z.real * z.real) + (z.i * z.i)) >=  4)
		{
			 printf("distance (%f)ˆ2 + (%f)ˆ2 = %f\n",z.real, z.i, ((z.real * z.real) + (z.i * z.i)));
			printf("[ < 42] value is == %i \n", value);
			return value;
		}
		i++;
	}
	// printf("value is ==  %i \n", value);
	return value;
}

void put_my_px(t_data *img, int width, int height, int value)
{
	if (value >= 70)
		my_mlx_pixel_put(img, width, height, BLACK);
	else if (value >= 30 && value < 35 || (value >= 65 && value < 70))
		my_mlx_pixel_put(img, width, height, MIDNIGHT_BLUE);
	else if (value >= 25 && value < 30 || (value >= 60 && value < 65))
		my_mlx_pixel_put(img, width, height, DARK_BLUE);
	else if (value >= 20 && value < 25 || (value >= 55 && value < 60))
		my_mlx_pixel_put(img, width, height, NAVY_BLUE);
	else if (value >= 15 && value < 20 || (value >= 50 && value < 55))
		my_mlx_pixel_put(img, width, height, ROYAL_BLUE);
	else if (value >= 10 && value < 15 || (value >= 45 && value < 50))
		my_mlx_pixel_put(img, width, height, STEEL_BLUE);
	else if (value >= 5 && value < 10 || (value >= 40  && value < 45))
		my_mlx_pixel_put(img, width, height, SKY_BLUE);
	else if (value >= 1 && value < 5 || (value >= 35 && value < 40))
		my_mlx_pixel_put(img, width, height, LIGHT_BLUE);
}

int	main (void)
{
	void	*mlx;
	void	*mlx_win;
	
	float	width = 640;
	float height = 640;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "Hello world!");

	t_complex	z;
	t_complex	c;

	float	real_x;
	float	imaginary_y;

	t_data img;
	img.img = mlx_new_image(mlx, 640, 640);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);

	real_x = 2 / (width / 2);
	imaginary_y = 2 / (height / 2);

	int i;
	int	j;

	i = 0;
	// I quadrant
	while (i < (height / 2))
	{
		j = width / 2;
		while (j < width)
		{
			c.real = (j - (width / 2)) * real_x;
			c.i = (2 - (i * imaginary_y));
			int	value = interations(z, c);
			put_my_px(&img, j, i, value);
			j++;
		}
		i++;
		z.i-=z.i;
	}
	// II qudrant
	i = height / 2;
	while (i < height)
	{
		j = width / 2;
		while (j < width)
		{
			c.real = (j - (width / 2)) * real_x;
			c.i = (2 - (i * imaginary_y));
			int	value = interations(z, c);
			put_my_px(&img, j, i, value);
			j++;
		}
		i++;
		z.i-=z.i;
	}
	// III quadrant
	i = height / 2;
	while (i < height)
	{
		j = 0;
		while (j < (width / 2))
		{
			c.real = (j - (width / 2)) * real_x;
			c.i = (2 - (i * imaginary_y));
			int	value = interations(z, c);
			put_my_px(&img, j, i, value);
			j++;
		}
		i++;
		z.i-=z.i;
	}

	// IV quadrant
	i = 0;
	while (i < (height / 2))
	{
		j = 0;
		while (j < (width  / 2))
		{
			c.real = (j - (width / 2)) * real_x;
			c.i = (2 - (i * imaginary_y));
			int	value = interations(z, c);
			put_my_px(&img, j, i, value);
			j++;
		}
		i++;
		z.i-=z.i;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
