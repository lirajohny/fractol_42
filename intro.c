#include "minilibx-linux/mlx.h"
#include <stdlib.h>

/*
typedef	struct s_complex
{
	float	real;
	float	i;
}	t_complex;


int	interations(t_complex z, t_complex c)
{
	double	tmp_real;
	int value;
	int i = 0;
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
			// printf("distance (%f)ˆ2 + (%f)ˆ2 = %f\n",z.real,z.i, ((z.real * z.real) + (z.i * z.i)));
			// printf("[ < 42] value is == %i \n", value);
			return value;
		}
		i++;
	}
	// printf("value is ==  %i \n", value);
	return value;
}

void put_my_px(void *mlx, void *mlx_win, int width, int height, int value)
{
	if (value >= 80)
		mlx_pixel_put(mlx, mlx_win, width, height, 0xA2357E);
	else if (value >= 70 && value < 80)
		mlx_pixel_put(mlx, mlx_win, width, height, 0x9435A2);
	else if (value >= 60 && value < 70)
		mlx_pixel_put(mlx, mlx_win, width, height, 0x4B35A2);
	else if (value >= 50 && value < 60)
		mlx_pixel_put(mlx, mlx_win, width, height, 0x3559A2);
	else if (value >= 30 && value < 40)
		mlx_pixel_put(mlx, mlx_win, width, height, 0x47A235);
	else if (value >= 20 && value < 30)
		mlx_pixel_put(mlx, mlx_win, width, height, 0x81A235);
	else if (value >= 11 && value < 20)
		mlx_pixel_put(mlx, mlx_win, width, height, 0xA29735);
	else if (value >= 1 && value < 10)
		mlx_pixel_put(mlx, mlx_win, width, height, 0xA23C35);
}
*/

int	main (void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 650, 650, "Hello world!");

	mlx_pixel_put(mlx, mlx_win, 320, 320, 0x35A239);
	/*
	mlx_pixel_put(mlx, mlx_win, 0, 0, 0x35A239);
	mlx_pixel_put(mlx, mlx_win, 640, 0, 0x35A239);
	mlx_pixel_put(mlx, mlx_win, 640, 640, 0x35A239);
	mlx_pixel_put(mlx, mlx_win, 0, 640, 0x35A239);/*
	/*
	t_complex	z;
	t_complex	c;

	float	real_x;
	float	imaginary_y;

	real_x = 0.00625;	
	imaginary_y = 0.00625;
	
	//mlx_pixel_put(mlx, mlx_win, 320, 320, 0x35A239);
	int i;
	int	j;
	i = 0;
	// I quadrant
	while (i < 320)
	{
		j = 320;
		while (j < 640)
		{
			c.real = (j - 320) * real_x;
			c.i = (2 - (i * imaginary_y));
			int	value = interations(z, c);
			put_my_px(mlx, mlx_win, i, j, value);
			j++;
		}
		i++;
		z.i-=z.i;
	}
	// II qudrant
	i = 320;
	while (i < 640)
	{
		j = 320;
		while (j < 640)
		{
			c.real = (j - 320) * real_x;
			c.i = (2 - (i * imaginary_y));
			int	value = interations(z, c);
			put_my_px(mlx, mlx_win, i, j, value);
			j++;
		}
		i++;
		z.i-=z.i;
	}
	// III quadrant
	i = 320;
	while (i < 640)
	{
		j = 0;
		while (j < 320)
		{
			c.real = (j - 320) * real_x;
			c.i = (2 - (i * imaginary_y));
			int	value = interations(z, c);
			put_my_px(mlx, mlx_win, i, j, value);
			j++;
		}
		i++;
		z.i-=z.i;
	}

	// IV quadrant
	i = 0;
	while (i < 320)
	{
		j = 0;
		while (j < 320)
		{
			c.real = (j - 320) * real_x;
			c.i = (2 - (i * imaginary_y));
			int	value = interations(z, c);
			put_my_px(mlx, mlx_win, i, j, value);
			j++;
		}
		i++;
		z.i-=z.i;
	}
	*/
	mlx_loop(mlx);
}
