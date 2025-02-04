/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:10:11 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/04 02:01:13 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_vertical_line(t_renderer *renderer, t_map *map, int x, int y);
static void	draw_horizontal_line(t_renderer *renderer,
				t_map *map, int x, int y);

void	draw_line(t_renderer *renderer, t_point start, t_point end)
{
	bresenham_draw(renderer, start, end);
}

void	init_line_params(t_point start, t_point end,
			t_point *delta, t_point *sign)
{
	delta->x = fabsf(end.x - start.x);
	delta->y = fabsf(end.y - start.y);
	if (start.x < end.x)
		sign->x = 1;
	else
		sign->x = -1;
	if (start.y < end.y)
		sign->y = 1;
	else
		sign->y = -1;
}

static void	draw_horizontal_line(t_renderer *renderer, t_map *map, int x, int y)
{
	t_point	start;
	t_point	end;

	start = project_point(renderer, x, y, map->grid[y][x]);
	if (x < map->width - 1)
	{
		end = project_point(renderer, x + 1, y, map->grid[y][x + 1]);
		draw_line(renderer, start, end);
	}
}

static void	draw_vertical_line(t_renderer *renderer, t_map *map, int x, int y)
{
	t_point	start;
	t_point	end;

	start = project_point(renderer, x, y, map->grid[y][x]);
	if (y < map->height - 1)
	{
		end = project_point(renderer, x, y + 1, map->grid[y + 1][x]);
		draw_line(renderer, start, end);
	}
}

void	draw_map_lines(t_renderer *renderer, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			draw_horizontal_line(renderer, map, x, y);
			draw_vertical_line(renderer, map, x, y);
			x++;
		}
		y++;
	}
}
