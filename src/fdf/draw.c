/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:18:22 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/04 02:47:55 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_map_lines(t_renderer *renderer, t_map *map, int x, int y);
static double	calculate_t(t_point start, t_point end, t_point cur);

void	bresenham_draw(t_renderer *renderer, t_point start, t_point end)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];
	double	t;

	init_line_params(start, end, &delta, &sign);
	error[0] = delta.x - delta.y;
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		t = calculate_t(start, end, cur);
		put_pixel(renderer, cur.x, cur.y, i_color(start.color, end.color, t));
		error[1] = 2 * error[0];
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

static double	calculate_t(t_point start, t_point end, t_point cur)
{
	double	dx;
	double	dy;
	double	line_length;
	double	current_length;

	dx = end.x - start.x;
	dy = end.y - start.y;
	line_length = sqrt(dx * dx + dy * dy);
	current_length = sqrt((cur.x - start.x) * (cur.x - start.x)
			+ (cur.y - start.y) * (cur.y - start.y));
	return (current_length / line_length);
}

static void	draw_map_lines(t_renderer *renderer, t_map *map, int x, int y)
{
	t_point	start;
	t_point	end;

	start = project_point(renderer, x, y, map->grid[y][x]);
	start.color = get_color(map, x, y);
	if (x + 1 < map->width)
	{
		end = project_point(renderer, x + 1, y, map->grid[y][x + 1]);
		draw_line(renderer, start, end);
	}
	if (y + 1 < map->height)
	{
		end = project_point(renderer, x, y + 1, map->grid[y + 1][x]);
		draw_line(renderer, start, end);
	}
}

void	render_map(t_renderer *renderer)
{
	int	x;
	int	y;

	y = -1;
	while (++y < renderer->map->height)
	{
		x = -1;
		while (++x < renderer->map->width)
			draw_map_lines(renderer, renderer->map, x, y);
	}
}
