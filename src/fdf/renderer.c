/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:42 by fvon-de           #+#    #+#             */
/*   Updated: 2025/02/18 21:02:01 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_image(t_renderer *renderer);

int	put_pixel(t_renderer *renderer, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < renderer->win_width
		&& y >= 0 && y < renderer->win_height)
	{
		dst = renderer->mlx.img_data + (y * renderer->mlx.line_length
				+ x * (renderer->mlx.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
	return (EXIT_SUCCESS);
}

int init_renderer(t_renderer *renderer)
{
    renderer->mlx.mlx_ptr = mlx_init();
    if (!renderer->mlx.mlx_ptr)
	{
        log_error("Error: Failed to initialize MLX");
        return (EXIT_FAILURE);
    }
    renderer->win_width = 800;
    renderer->win_height = 600;
    renderer->mlx.win_ptr = mlx_new_window(renderer->mlx.mlx_ptr,
                                           renderer->win_width, renderer->win_height, "FdF");
    if (!renderer->mlx.win_ptr)
	{
        log_error("Error: Failed to create window");
        return (EXIT_FAILURE);
    }
    if (init_image(renderer) == EXIT_FAILURE)
	{
        mlx_destroy_window(renderer->mlx.mlx_ptr, renderer->mlx.win_ptr);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int init_image(t_renderer *renderer)
{
    renderer->mlx.img_ptr = mlx_new_image(renderer->mlx.mlx_ptr,
                                           renderer->win_width, renderer->win_height);
    if (!renderer->mlx.img_ptr)
	{
        log_error("Error creating image");
        return (EXIT_FAILURE);
    }
    renderer->mlx.img_data = mlx_get_data_addr(renderer->mlx.img_ptr,
                                               &renderer->mlx.bits_per_pixel, &renderer->mlx.line_length,
                                               &renderer->mlx.endian);
    if (!renderer->mlx.img_data)
	{
        mlx_destroy_image(renderer->mlx.mlx_ptr, renderer->mlx.img_ptr);
        return (EXIT_FAILURE); 
    }
    return (EXIT_SUCCESS);
}
