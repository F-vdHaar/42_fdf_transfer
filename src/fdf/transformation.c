/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:53:43 by fvon-der          #+#    #+#             */
/*   Updated: 2024/07/08 13:01:27 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fdf.h"

void	handle_translate(t_map *map, int dx, int dy)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->map[y][x] += dx;
			map->map[y][x] += dy;
			x++;
		}
		y++;
	}
}

void	handle_zoom(t_map *map, int factor)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->map[y][x] *= factor;
			x++;
		}
		y++;
	}
}

void	handle_scale(t_map *map, double x_scale, double y_scale, double z_scale)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->map[y][x] *= x_scale;
			map->map[y][x] *= y_scale;
			map->map[y][x] *= z_scale;
			x++;
		}
		y++;
	}
}

void	handle_rotate(t_map *map, double x_angle,
			double y_angle, double z_angle)
{
	rotate_x(map->map, map->width, map->height, x_angle);
	rotate_y(map->map, map->width, map->height, y_angle);
	rotate_z(map->map, map->width, map->height, z_angle);
}
