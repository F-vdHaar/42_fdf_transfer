/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:53:43 by fvon-der          #+#    #+#             */
/*   Updated: 2025/01/12 13:41:04 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_translate(t_renderer *renderer, double dx, double dy)
{
	double	y;
	double	x;

	y = 0;
	while (y < renderer->map->height)
	{
		x = 0;
		while (x < renderer->map->width)
		{
			renderer->map->map[y][x] += dx;
			renderer->map->map[y][x] += dy;
			x++;
		}
		y++;
	}
}

void	handle_zoom(t_renderer *renderer, double factor)
{
	int	y;
	int	x;

	y = 0;
	while (y < renderer->map->height)
	{
		x = 0;
		while (x < renderer->map->width)
		{
			renderer->map->map[y][x] *= factor;
			x++;
		}
		y++;
	}
}

void	handle_scale(t_renderer *renderer, double x_scale, double y_scale, double z_scale)
{
	int	y;
	int	x;

	y = 0;
	while (y < renderer->map->height)
	{
		x = 0;
		while (x < renderer->map->width)
		{
			map->map[y][x] *= x_scale;
			map->map[y][x] *= y_scale;
			map->map[y][x] *= z_scale;
			x++;
		}
		y++;
	}
}

void	handle_rotate(t_renderer *renderer, double x_angle,
			double y_angle, double z_angle)
{
	rotate_x(renderer->map->map, map->width, map->height, x_angle);
	rotate_y(renderer->map->map, map->width, map->height, y_angle);
	rotate_z(renderer->map->map, map->width, map->height, z_angle);
}
