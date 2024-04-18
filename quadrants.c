#include "fractol.h"

static t_fill first_fourth(t_data *img, int i, int j, t_fill value)
{
	float	real_x;
	float	imaginary_y;

	real_x = 2.0 / (value.width / 2.0);
	imaginary_y = 2.0 / (value.height / 2.0);
	value.c.real = (j - (value.width / 2)) * real_x;
	value.c.i = (2 - (i * imaginary_y));
	int	nbr = interations(value.z, value.c);
	put_my_px(img, j, i, nbr);
	return (value);
}
static t_fill	second_third(t_data *img, int i, int j, t_fill value)
{
	float	real_x;
	float	imaginary_y;

	real_x = 2.0 / (value.width / 2.0);
	imaginary_y = 2.0 / (value.height / 2.0);
	value.c.real = (j - (value.width / 2)) * real_x;
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
			if (i <= 0 && i < height / 2) // I quadrant && VI quadrant
				value = first_fourth(img, i, j, value);
			else // II qudrant && III quadrant
				value = second_third(img, i, j, value);
			j++;
		}
		value.z.i-=value.z.i;
		i++;
	}
}
