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
int	main (void)
{
	t_complex	z;
	t_complex	c;
	int arr[640][640] = {0};

	c.real = 0;
	c.i = 0;
	z.real = 0;
	z.i = 0;

	int i = 0;
	int j = 0;
	float real_x = 0.00625;
	float imaginary_y = 0.00625;

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
			arr[i][j] = value;
			j++;
		}
		i++;
		z.i-=z.i;
	}
	// II quadrant
	i = 320;
	while (i < 640)
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
			arr[i][j] = value;
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
			arr[i][j] = value;
			j++;
		}
		i++;
		z.i-=z.i;
	}

	// print
	i = 0;
	while (i < 640)
	{
		j = 0;
		while (j < 640)
		{
			if (arr[i][j] >= 88 && arr[i][j] <= 89)
				printf("\033[0;30mx\033[0m");   // Black
			else if (arr[i][j] >= 85 && arr[i][j] <= 87)
				printf("\033[0;97mx\033[0m");   // Light White
			else if (arr[i][j] >= 83 && arr[i][j] <= 84)
				printf("\033[0;93mx\033[0m");   // Light Blue
			else if (arr[i][j] >= 81 && arr[i][j] <= 82)
				printf("\033[0;92mx\033[0m");   // Light Green
			else if (arr[i][j] >= 79 && arr[i][j] <= 80)
				printf("\033[0;34mx\033[0m");   // Blue
			else if (arr[i][j] >= 77 && arr[i][j] <= 78)
				printf("\033[0;32mx\033[0m");   // Green
			else if (arr[i][j] >= 75 && arr[i][j] <= 76)
				printf("\033[0;96mx\033[0m");   // Light Yellow
			else if (arr[i][j] >= 73 && arr[i][j] <= 74)
				printf("\033[0;91mx\033[0m");   // Light Red
			else if (arr[i][j] >= 71 && arr[i][j] <= 72)
				printf("\033[0;33mx\033[0m");   // Yellow
			else if (arr[i][j] >= 69 && arr[i][j] <= 70)
				printf("\033[0;31mx\033[0m");   // Red
			else if (arr[i][j] >= 67 && arr[i][j] <= 68)
				printf("\033[0;98mx\033[0m");   // Light Gray
			else if (arr[i][j] >= 65 && arr[i][j] <= 66)
				printf("\033[0;98mx\033[0m");   // Light Gray
			else if (arr[i][j] >= 63 && arr[i][j] <= 64)
				printf("\033[0;95mx\033[0m");   // Light Cyan
			else if (arr[i][j] >= 61 && arr[i][j] <= 62)
				printf("\033[0;36mx\033[0m");   // Cyan
			else if (arr[i][j] >= 59 && arr[i][j] <= 60)
				printf("\033[0;97mx\033[0m");   // White
			else if (arr[i][j] >= 57 && arr[i][j] <= 58)
				printf("\033[0;94mx\033[0m");   // Light Magenta
			else if (arr[i][j] >= 55 && arr[i][j] <= 56)
				printf("\033[0;35mx\033[0m");   // Magenta
			else if (arr[i][j] >= 53 && arr[i][j] <= 54)
				printf("\033[0;90mx\033[0m");   // Gray
			else if (arr[i][j] >= 51 && arr[i][j] <= 52)
				printf("\033[0;97mx\033[0m");   // Light White
			else if (arr[i][j] >= 49 && arr[i][j] <= 50)
				printf("\033[0;93mx\033[0m");   // Light Blue
			else if (arr[i][j] >= 47 && arr[i][j] <= 48)
				printf("\033[0;92mx\033[0m");   // Light Green
			else if (arr[i][j] >= 45 && arr[i][j] <= 46)
				printf("\033[0;34mx\033[0m");   // Blue
			else if (arr[i][j] >= 43 && arr[i][j] <= 44)
				printf("\033[0;32mx\033[0m");   // Green
			else if (arr[i][j] >= 41 && arr[i][j] <= 42)
				printf("\033[0;96mx\033[0m");   // Light Yellow
			else if (arr[i][j] >= 39 && arr[i][j] <= 40)
				printf("\033[0;91mx\033[0m");   // Light Red
			else if (arr[i][j] >= 37 && arr[i][j] <= 38)
				printf("\033[0;33mx\033[0m");   // Yellow
			else if (arr[i][j] >= 35 && arr[i][j] <= 36)
				printf("\033[0;31mx\033[0m");   // Red
			else if (arr[i][j] >= 33 && arr[i][j] <= 34)
				printf("\033[0;98mx\033[0m");   // Light Gray
			else if (arr[i][j] >= 31 && arr[i][j] <= 32)
				printf("\033[0;98mx\033[0m");   // Light Gray
			else if (arr[i][j] >= 29 && arr[i][j] <= 30)
				printf("\033[0;95mx\033[0m");   // Light Cyan
			else if (arr[i][j] >= 27 && arr[i][j] <= 28)
				printf("\033[0;36mx\033[0m");   // Cyan
			else if (arr[i][j] >= 25 && arr[i][j] <= 26)
				printf("\033[0;97mx\033[0m");   // White
			else if (arr[i][j] >= 23 && arr[i][j] <= 24)
				printf("\033[0;94mx\033[0m");   // Light Magenta
			else if (arr[i][j] >= 21 && arr[i][j] <= 22)
				printf("\033[0;35mx\033[0m");   // Magenta
			else if (arr[i][j] >= 19 && arr[i][j] <= 20)
				printf("\033[0;90mx\033[0m");   // Gray
			else if (arr[i][j] >= 17 && arr[i][j] <= 18)
				printf("\033[0;97mx\033[0m");   // Light White
			else if (arr[i][j] >= 15 && arr[i][j] <= 16)
				printf("\033[0;93mx\033[0m");   // Light Blue
			else if (arr[i][j] >= 13 && arr[i][j] <= 14)
				printf("\033[0;92mx\033[0m");   // Light Green
			else if (arr[i][j] >= 11 && arr[i][j] <= 12)
				printf("\033[0;34mx\033[0m");   // Blue
			else if (arr[i][j] >= 9 && arr[i][j] <= 10)
				printf("\033[0;32mx\033[0m");   // Green
			else if (arr[i][j] >= 7 && arr[i][j] <= 8)
				printf("\033[0;96mx\033[0m");   // Light Yellow
			else if (arr[i][j] >= 5 && arr[i][j] <= 6)
				printf("\033[0;91mx\033[0m");   // Light Red
			else if (arr[i][j] >= 3 && arr[i][j] <= 4)
				printf("\033[0;33mx\033[0m");   // Yellow
			else if (arr[i][j] >= 1 && arr[i][j] <= 2)
				printf("\033[0;31mx\033[0m");   // Red
			else
				printf("A");
			j++;
		}
		i++;
	}
}
