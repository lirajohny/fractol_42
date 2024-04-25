/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:59:01 by jlira             #+#    #+#             */
/*   Updated: 2024/04/25 10:54:21 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_colors	pattern_1(int value, int variation)
{
	t_colors	range;

	if (variation == 0)
	{
		range.pallet[0] = C1;
		range.pallet[1] = C2;
		range.pallet[2] = C3;
		range.pallet[3] = C4;
		range.pallet[4] = C5;
		range.pallet[5] = C6;
	}
	else
	{
		range.pallet[0] = C1;
		range.pallet[1] = C6;
		range.pallet[2] = C2;
		range.pallet[3] = C5;
		range.pallet[4] = C3;
		range.pallet[5] = C4;
	}
	range.rgb = range.pallet[(value / 20) % 6];
	range.red = (range.rgb >> 16) & 0xFF;
	range.green = (range.rgb >> 8) & 0xFF;
	range.blue = range.rgb & 0xFF;
	return (range);
}

t_colors	pattern_2(int value, int variation)
{
	t_colors	range;

	if (variation == 0)
	{
		range.pallet[0] = C2;
		range.pallet[1] = C1;
		range.pallet[2] = C4;
		range.pallet[3] = C3;
		range.pallet[4] = C6;
		range.pallet[5] = C5;
	}
	else
	{
		range.pallet[0] = C6;
		range.pallet[1] = C2;
		range.pallet[2] = C1;
		range.pallet[3] = C4;
		range.pallet[4] = C3;
		range.pallet[5] = C5;
	}
	range.rgb = range.pallet[(value / 20) % 6];
	range.red = (range.rgb >> 16) & 0xFF;
	range.green = (range.rgb >> 8) & 0xFF;
	range.blue = range.rgb & 0xFF;
	return (range);
}

t_colors	pattern_3(int value, int variation)
{
	t_colors	range;

	if (variation == 0)
	{
		range.pallet[0] = C4;
		range.pallet[1] = C1;
		range.pallet[2] = C6;
		range.pallet[3] = C2;
		range.pallet[4] = C3;
		range.pallet[5] = C5;
	}
	else
	{
		range.pallet[0] = C5;
		range.pallet[1] = C4;
		range.pallet[2] = C1;
		range.pallet[3] = C2;
		range.pallet[4] = C3;
		range.pallet[5] = C6;
	}
	range.rgb = range.pallet[(value / 20) % 6];
	range.red = (range.rgb >> 16) & 0xFF;
	range.green = (range.rgb >> 8) & 0xFF;
	range.blue = range.rgb & 0xFF;
	return (range);
}
t_colors	start_colors(int value, int key)
{

	if (key % 6 == 1)
		return (pattern_1(value, 0));
	else if (key % 6 == 2)
		return (pattern_2(value, 0));
	else if (key % 6 == 3)
		return (pattern_3(value, 0));
	else if (key % 6 == 4)
		return (pattern_1(value, 1));
	else if (key % 6 == 5)
		return (pattern_2(value, 1));
	else
		return (pattern_3(value, 1));
}

void	put_my_px(t_data *img, int j, int i, int value)
{
	t_colors	range;

	range = start_colors(value, img->max_iterations);
	if (value >= img->max_iterations)
		my_mlx_pixel_put(img, j, i, BLACK);
	else
	{
		if ((value / 20) % 6 == 0)
			range.green += 17 * (value % 20);
		else if ((value / 20) % 6 == 1)
			range.red -= 17 * (value % 20);
		else if ((value / 20) % 6 == 2)
			range.blue += 17 * (value % 20);
		else if ((value / 20) % 6 == 3)
			range.green -= 17 * (value % 20);
		else if ((value / 20) % 6 == 4)
			range.red += 17 * (value % 20);
		else if ((value / 10) % 6 == 5)
			range.blue += 17 * (value % 10);
		range.new_rgb = (range.red << 16) | (range.green << 8) | range.blue;
		my_mlx_pixel_put(img, j, i, range.new_rgb);
	}
}
