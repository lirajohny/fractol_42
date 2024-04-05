#include <stdio.h>

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

int	main (void)
{
	t_complex	z;
	t_complex	c;
	c.real = 0;
	c.i = 0;
	z.real = 0;
	z.i = 0;

	// I quadrant
	int arr[640][640] = {0};
	int i = 0;
	int j = 0;
	float real_x = 0.00625; // as i chose 640x640 to display the fractal and it fits in a circle radius 2. I divides 2 by 640 so I could have as many points as possible to check.
	float imaginary_y = 0.00625;
	while (i < 320)
	{
		j = 320;
		while (j < 640)
		{
			c.real = (j - 320) * real_x;
			c.i = (2 - (i * imaginary_y));
			int	value = interations(z, c);
			arr[i][j] = value;
			j++;
		}
		i++;
		z.i-=z.i;
	}
}
