
void put_my_px(t_data *img, int width, int height, int value)
{
	int pallet[8] = {0x80FF00, 0x00FF00, 0x00FF80,0x00FFFF, 0x0080FF, 0x0000FF, 0x7F00FF, 0xFF00FF};
	if (value >= 360)
		my_mlx_pixel_put(img, width, height, BLACK);
	else
	{
		int rgb = pallet[(value / 5) % 8];
		int red = (rgb >> 16) & 0xFF;  
		int green = (rgb >> 8) & 0xFF;
		int blue = rgb & 0xFF;       
		if ((value / 5) % 8 == 0)
			red += 24 * (value % 5);
		if ((value / 5) % 8 == 1)
			blue += 24 * (value % 5);
		else if ((value / 5) % 8 == 2)
			blue += 24 * (value % 5);
		else if ((value / 5) % 8 == 3)
			green -= 24 * (value % 5);
		else if ((value / 5) % 8 == 4)
			green -= 24 * (value % 5);
		else if ((value / 5) % 8 == 5)
			red += 24 * (value % 5) ;
		else if ((value / 5) % 8 == 6)
			red += 24 * (value % 5);
		else if ((value / 5) % 8 == 7)
			blue -= 24 * (value % 5);
		int new_rgb = (red << 16) | (green << 8) | blue;
		my_mlx_pixel_put(img, width, height, new_rgb);
	}
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

