/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:18:22 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/27 14:10:54 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	calculate_t(t_point *start, t_point *end, t_point cur);
static void		handle_error(int *error, t_point *cur,
					t_point sign, t_point delta);
static int		is_outside_window(t_renderer *renderer,
					t_point *start, t_point *end);
static void		draw_pixel_if_valid(t_renderer *renderer, t_point *start,
					t_point *end, t_point cur);

int	bresenham_draw(t_renderer *renderer, t_point *start, t_point *end)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	if (!start || !end)
		return (ft_printf("ERROR: start or end is NULL!\n"), EXIT_FAILURE);
	if (is_outside_window(renderer, start, end))
		return (EXIT_SUCCESS);
	init_line_params(*start, *end, &delta, &sign);
	error[0] = delta.x - delta.y;
	cur = *start;
	while (cur.x != end->x || cur.y != end->y)
	{
		draw_pixel_if_valid(renderer, start, end, cur);
		handle_error(error, &cur, sign, delta);
	}
	return (EXIT_SUCCESS);
}

static void	draw_pixel_if_valid(t_renderer *renderer, t_point *start,
								t_point *end, t_point cur)
{
	double	t;
	int		color;

	if (cur.x >= 0 && cur.x < renderer->win_width
		&& cur.y >= 0 && cur.y < renderer->win_height)
	{
		t = calculate_t(start, end, cur);
		color = i_color(start->color, end->color, t);
		put_pixel(renderer, cur.x, cur.y, color);
	}
}

static void	handle_error(int *error, t_point *cur, t_point sign, t_point delta)
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

static int	is_outside_window(t_renderer *renderer,
								t_point *start, t_point *end)
{
	if ((start->x < 0 || start->x >= renderer->win_width
			|| start->y < 0 || start->y >= renderer->win_height)
		&& (end->x < 0 || end->x >= renderer->win_width
			|| end->y < 0 || end->y >= renderer->win_height))
	{
		return (1);
	}
	return (0);
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
