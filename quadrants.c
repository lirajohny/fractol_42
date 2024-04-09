#include "fractol.h"

void	quadrants_fill(t_data *img, float width, float height)
{
	float	real_x;
	float	imaginary_y;
	t_complex	z;
	int i;
	int	j;
	t_complex	c;
	z.i = 0;
	z.real = 0;
	c.i = 0;
	c.real = 0;

	real_x = 2 / (width / 2);
	imaginary_y = 2 / (height / 2);
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
			put_my_px(img, j, i, value);
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
			put_my_px(img, j, i, value);
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
			put_my_px(img, j, i, value);
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
			put_my_px(img, j, i, value);
			j++;
		}
		i++;
		z.i-=z.i;
	}
}
