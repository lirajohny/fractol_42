/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:59:01 by jlira             #+#    #+#             */
/*   Updated: 2024/04/22 11:02:59 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_colors	start_colors(int value)
{
	t_colors	range;

	range.pallet[0] = C1;
	range.pallet[1] = C2;
	range.pallet[2] = C3;
	range.pallet[3] = C4;
	range.pallet[4] = C5;
	range.pallet[5] = C6;
	range.rgb = range.pallet[(value / 5) % 6];
	range.red = (range.rgb >> 16) & 0xFF;
	range.green = (range.rgb >> 8) & 0xFF;
	range.blue = range.rgb & 0xFF;
	return (range);
}

void	put_my_px(t_data *img, int j, int i, int value)
{
	t_colors	range;

	range = start_colors(value);
	if (value >= img->max_iterations)
		my_mlx_pixel_put(img, j, i, BLACK);
	else
	{
		if ((value / 5) % 6 == 0)
			range.blue += 24 * (value % 5);
		else if ((value / 5) % 6 == 1)
			range.blue += 24 * (value % 5);
		else if ((value / 5) % 6 == 2)
			range.green -= 24 * (value % 5);
		else if ((value / 5) % 6 == 3)
			range.green -= 24 * (value % 5);
		else if ((value / 5) % 6 == 4)
			range.red += 24 * (value % 5);
		else if ((value / 5) % 6 == 5)
			range.red += 24 * (value % 5);
		range.new_rgb = (range.red << 16) | (range.green << 8) | range.blue;
		my_mlx_pixel_put(img, j, i, range.new_rgb);
	}
}
