/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:18:22 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/27 07:41:45 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	calculate_t(t_point *start, t_point *end, t_point cur);
static void		draw_line_pixels(t_renderer *renderer, t_point *start,
					t_point *end, t_point delta);
static void		draw_pixel_if_visible(t_renderer *renderer, t_point *cur,
					t_point *start, t_point *end);
static void		update_error_and_position(t_point *cur, t_point sign,
					int error[2], t_point delta);

static void	update_error_and_position(t_point *cur, t_point sign,
	int error[2], t_point delta)
{
	error[1] = 2 * error[0];
	if (error[1] > -delta.y)
	{
		error[0] -= delta.y;
		cur->x += sign.x;
	}
	if (error[1] < delta.x)
	{
		error[0] += delta.x;
		cur->y += sign.y;
	}
}

static void	draw_pixel_if_visible(t_renderer *renderer, t_point *cur,
	t_point *start, t_point *end)
{
	double	t;
	int		color;

	if (cur->x >= 0 && cur->x < renderer->win_width
		&& cur->y >= 0 && cur->y < renderer->win_height)
	{
		t = calculate_t(start, end, *cur);
		color = i_color(start->color, end->color, t);
		put_pixel(renderer, cur->x, cur->y, color);
	}
}

static void	draw_line_pixels(t_renderer *renderer, t_point *start,
	t_point *end, t_point delta)
{
	t_point	sign;
	t_point	cur;
	int		error[2];

	init_line_params(*start, *end, &delta, &sign);
	error[0] = delta.x - delta.y;
	cur = *start;
	while (cur.x != end->x || cur.y != end->y)
	{
		draw_pixel_if_visible(renderer, &cur, start, end);
		update_error_and_position(&cur, sign, error, delta);
	}
}

int	bresenham_draw(t_renderer *renderer, t_point *start, t_point *end)
{
	t_point	delta;

	if (is_outside_window(renderer, start, end))
		return (EXIT_SUCCESS);
	delta.x = abs(end->x - start->x);
	delta.y = abs(end->y - start->y);
	draw_line_pixels(renderer, start, end, delta);
	return (EXIT_SUCCESS);
}

static double	calculate_t(t_point *start, t_point *end, t_point cur)
{
	int	dx;
	int	dy;
	int	line_length;
	int	cur_length;

	dx = abs(end->x - start->x);
	dy = abs(end->y - start->y);
	line_length = dx;
	if (dy > dx)
		line_length = dy;
	cur_length = abs(cur.x - start->x);
	if (abs(cur.y - start->y) > cur_length)
		cur_length = abs(cur.y - start->y);
	if (line_length == 0)
		return (0.0);
	return ((double)cur_length / (double)line_length);
}
