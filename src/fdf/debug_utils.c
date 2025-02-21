/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:45:39 by fvon-de           #+#    #+#             */
/*   Updated: 2025/02/20 18:02:55 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void draw_square(t_renderer *renderer, int x, int y, int color);

int	debug_print_nums_char(char **nums)
{
	int i = 0;
	if (!nums) {
		ft_printf("DEBUG : nums is NULL\n");
		return (EXIT_FAILURE);
	}
	
	while (nums[i]) {
		ft_printf("DEBUG : nums[%d]: \"%s\"\n", i, nums[i]);
		i++;
	}
    return (EXIT_SUCCESS);
}

int debug_print_map(t_renderer *renderer)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("DEBUG :[debug_print_map] \n map Z values -----------\n");
	while (i < renderer->map->height)
	{
		j = 0;
		while (j < renderer->map->width)
		{
			ft_printf("%d ", renderer->map->grid[i][j]);
			j++;
		}
		write(1, "\n", sizeof(char));
		i++;
	}
	ft_printf("DEBUG :[debug_print_map] \n map  COLOR -----------\n");
	i = 0;
	while (i < renderer->map->height)
	{
		j = 0;
		while (j < renderer->map->width)
		{
			ft_printf("%d ", renderer->map->color[i][j]);
			j++;
		}
		write(1, "\n", sizeof(char));
		i++;
	}
    return (EXIT_SUCCESS);
}

static void	draw_square(t_renderer *renderer, int x, int y, int color)
{
	int		square_size;
	int		i;
	int		j;

	square_size = 10;
	i = x;
	while (i < x + square_size)
	{
		j = y;
		while (j < y + square_size)
		{
			if (i < renderer->win_width && j < renderer->win_height)
				mlx_pixel_put(renderer->mlx.mlx_ptr, renderer->mlx.win_ptr, i, j, color);
			j++;
		}
		i++;
	}
}

int	debug_render_grid(t_renderer *renderer)
{
	int		x;
	int		y;
	int		color;
	int		value;

	y = 0;
	while (y < renderer->map->height)
	{
		x = 0;
		while (x < renderer->map->width)
		{
			value = renderer->map->grid[y][x];
			if (value == -1)
				color = 0xFF0000;
			else if (value == 0)
				color = 0x800080;
			else if (value == 1)
				color = 0x0000FF;
			else
				color = 0xFFFFFF;
			draw_square(renderer, x * 20, y * 20, color);
			x++;
		}
		y++;
	}
    return (EXIT_SUCCESS);
}
