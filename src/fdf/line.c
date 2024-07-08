/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:10:11 by fvon-der          #+#    #+#             */
/*   Updated: 2024/07/08 13:46:29 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fdf.h"

void	draw_line(t_renderer *renderer, t_point start, t_point end, int color)
{
	bresenham_draw(renderer, start, end, color);
}

static void	init_line_params(t_point start, t_point end,
t_point *delta, t_point *sign)
{
	delta->x = abs(end.x - start.x);
	delta->y = abs(end.y - start.y);
	if (start.x < end.x)
		sign->x = 1;
	else
		sign->x = -1;
	if (start.y < end.y)
		sign->y = 1;
	else
		sign->y = -1;
}

static void	draw_vertical_lines(t_renderer *renderer, t_map *map, int x, int y)
{
	t_point	start;
	t_point	end;

	if (y < map->height - 1)
	{
		start.x = x;
		start.y = y;
		end.x = x;
		end.y = y + 1;
		draw_line(renderer, start, end, 0xFFFFFF);
	}
}

static void	draw_horizontal_lines(t_renderer *renderer,
t_map *map, int x, int y)
{
	t_point	start;
	t_point	end;

	if (x < map->width - 1)
	{
		start.x = x;
		start.y = y;
		end.x = x + 1;
		end.y = y;
		draw_line(renderer, start, end, 0xFFFFFF);
	}
}
