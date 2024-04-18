#include "fractol.h"

void	quadrants_fill(t_data *img, float width, float height)
{
	float	real_x;
	float	imaginary_y;
	t_complex	z;
	t_complex	c;
	int i;
	int	j;

	z.i = 0;
	z.real = 0;
	c.i = 0;
	c.real = 0;

	real_x = 2.0 / (width / 2.0);
	imaginary_y = 2.0 / (height / 2.0);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i <= 0 && i < height / 2)
			{
				// I quadrant && VI quadrant
				c.real = (j - (width / 2)) * real_x;
				c.i = (2 - (i * imaginary_y));
				int	value = interations(z, c);
				put_my_px(img, j, i, value);
			}
			else
			{
				// II qudrant && III quadrant
				c.real = (j - (width / 2)) * real_x;
				c.i = ((height / 2) - i) * imaginary_y;
				int	value = interations(z, c);
				put_my_px(img, j, i, value);
			}
			j++;
		}
		z.i-=z.i;
		i++;
	}
}
/* learn how an image is writen/read in c
void	change_colors(t_data *img, float width, float height)
{
	int	i;
	int	j;
	i = 0;
	j = 0;

    int rgb = 0x05111E;
	// 6BC997 to 6BC9C9 / b 150 to 201   
	
    int red = (rgb >> 16) & 0xFF;   // Componente Vermelho (R)
    int green = (rgb >> 8) & 0xFF;  // Componente Verde (G)
    int blue = rgb & 0xFF;          // Componente Azul (B)
			blue += 4 * diff;
        int new_rgb = (red << 16) | (green << 8) | blue;
		my_mlx_pixel_put(img, width, height, new_rgb);
}*/
