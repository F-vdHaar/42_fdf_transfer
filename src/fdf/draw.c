/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:18:22 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/18 20:59:01 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	calculate_t(t_point *start, t_point *end, t_point cur);


int	bresenham_draw(t_renderer *renderer, t_point *start, t_point *end)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];
	double	t;

	if (!start || !end) 
	{
		ft_printf("ERROR: start or end is NULL!\n");
		return;	
	}

	// **Check if both start and end are completely outside the window**
	if ((start->x < 0 || start->x >= renderer->win_width || start->y < 0 || start->y >= renderer->win_height) &&
		(end->x < 0 || end->x >= renderer->win_width || end->y < 0 || end->y >= renderer->win_height))
	{
		ft_printf("WARNING: Line is completely outside the window, skipping drawing.\n");
		return;
	}

	ft_printf("DEBUG: [bresenham_draw] Start drawing from x = %i, y = %i to x = %i, y = %i\n", 
		(int)start->x, (int)(start->x), 
		(int)start->y, (int)(start->y),
		(int)end->x, (int)(end->x), 
		(int)end->y, (int)(end->y)) ;

	init_line_params(*start, *end, &delta, &sign);
	error[0] = delta.x - delta.y;
	cur = *start;

	while (cur.x != end->x || cur.y != end->y)
	{
		// **Only draw if the current point is inside the window boundaries**
		if (cur.x >= 0 && cur.x < renderer->win_width && cur.y >= 0 && cur.y < renderer->win_height)
		{
			t = calculate_t(start, end, cur);
			put_pixel(renderer, cur.x, cur.y, 0xFFFFF);

			//put_pixel(renderer, cur.x, cur.y, i_color(start->color, end->color, t));
		}

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

	ft_printf("DEBUG: [bresenham_draw] Finished drawing the line\n");
	mlx_put_image_to_window(renderer->mlx.mlx_ptr, renderer->mlx.win_ptr, renderer->mlx.img_ptr, 0, 0);
    return (EXIT_SUCCESS);
}

static int	calculate_t(t_point *start, t_point *end, t_point cur)
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
		return (0);
	return (cur_length * 255 / line_length);
}

int	render_map(t_renderer *renderer)
{
	int	x;
	int	y;


	y = -1;
	while (++y < renderer->map->height)
	{
		ft_printf("DEBUG: [render_map] Rendering row %d (y = %d)\n", y, y);
		x = -1;
		while (++x < renderer->map->width)
		{
			ft_printf("DEBUG: [render_map] Rendering column %d (x = %d), grid value = %d\n",
				x, x, renderer->map->grid[y][x]);
			draw_map_line(renderer, renderer->map);
				// TODO check if obsolete
				//draw_map_lines(renderer, renderer->map, x, y);
		}
	}

	ft_printf("DEBUG: [render_map] Map rendering completed, rows: %d, columns: %d\n", 
		renderer->map->height, renderer->map->width);
    return (EXIT_SUCCESS);
}
