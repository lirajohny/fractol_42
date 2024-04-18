#include "fractol.h"

static t_fill quadrants(t_data *img, int i, int j, t_fill value)
{
	float	real_x;
	float	imaginary_y;

	real_x = 3.0 / (value.width);
	imaginary_y = 2.5 / (value.height);
	value.c.real = (j - (value.width / 1.51515152)) * real_x;
	if (i <= 0 && i < value.height / 2) // I quadrant && VI quadrant
		value.c.i = (1.25 - (i * imaginary_y));
	else // II qudrant && III quadrant
		value.c.i = ((value.height / 2) - i) * imaginary_y;
	int	nbr = interations(value.z, value.c);
	put_my_px(img, j, i, nbr);
	return (value);
}

void	quadrants_fill(t_data *img, float width, float height)
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
}
