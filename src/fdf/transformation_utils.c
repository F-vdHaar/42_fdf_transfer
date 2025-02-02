/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:01:23 by fvon-der          #+#    #+#             */
/*   Updated: 2025/01/26 16:19:30 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int **map, int width, int height, double x_angle)
{
	int		y;
	int		x;
	double	temp_y;
	double	temp_z;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			temp_y = y * cos(x_angle) - map[y][x] * sin(x_angle);
			temp_z = y * sin(x_angle) + map[y][x] * cos(x_angle);
			y = temp_y;
			map[y][x] = temp_z;
			x++;
		}
		y++;
	}
}

void	rotate_y(int **map, int width, int height, double y_angle)
{
	int		y;
	int		x;
	double	temp_x;
	double	temp_z;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			temp_x = x * cos(y_angle) + map[y][x] * sin(y_angle);
			temp_z = -x * sin(y_angle) + map[y][x] * cos(y_angle);
			x = temp_x;
			map[y][x] = temp_z;
			x++;
		}
		y++;
	}
}

// void	rotate_z(int **map, int width, int height, double z_angle)
// {
// 	int		y;
// 	int		x;
// 	double	temp_x;
// 	double	temp_y;

// 	y = 0;
// 	while (y < height)
// 	{
// 		x = 0;
// 		while (x < width)
// 		{
// 			temp_x = x * cos(z_angle) - y * sin(z_angle);
// 			temp_y = x * sin(z_angle) + y * cos(z_angle);
// 			x = temp_x;
// 			y = temp_y;
// 			x++;
// 		}
// 		y++;
// 	}
// }
