/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:42 by fvon-de           #+#    #+#             */
/*   Updated: 2025/02/04 02:01:41 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_renderer *renderer, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < renderer->win_width
		&& y >= 0 && y < renderer->win_height)
	{
		dst = renderer->mlx.img_data + (y * renderer->mlx.line_length
				+ x * (renderer->mlx.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	init_renderer(t_renderer *renderer)
{
	renderer->mlx.mlx_ptr = mlx_init();
	if (!renderer->mlx.mlx_ptr)
	{
		log_error("Error initializing MLX");
		exit(EXIT_FAILURE);
	}
	renderer->win_width = 800;
	renderer->win_height = 600;
	renderer->mlx.win_ptr = mlx_new_window(renderer->mlx.mlx_ptr,
			renderer->win_width, renderer->win_height, "FdF");
	if (!renderer->mlx.win_ptr)
	{
		log_error("Error creating window");
		exit(EXIT_FAILURE);
	}
	init_image(renderer);
	renderer->is_focused = 1;
}

static void	init_image(t_renderer *renderer)
{
	renderer->mlx.img_ptr = mlx_new_image(renderer->mlx.mlx_ptr,
			renderer->win_width, renderer->win_height);
	if (!renderer->mlx.img_ptr)
	{
		log_error("Error creating image");
		exit(EXIT_FAILURE);
	}
	renderer->mlx.img_data = mlx_get_data_addr(renderer->mlx.img_ptr,
			&renderer->mlx.bits_per_pixel, &renderer->mlx.line_length,
			&renderer->mlx.endian);
}
