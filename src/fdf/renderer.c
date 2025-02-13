/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:42 by fvon-de           #+#    #+#             */
/*   Updated: 2025/02/13 04:15:03 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_image(t_renderer *renderer);

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
	if (!renderer)
	{
		printf("ERROR: Failed to allocate memory for renderer\n");
		log_error("Error initializing MLX");
		exit(EXIT_FAILURE);
	}
	ft_printf("DEBUG: mlx init\n");
	renderer->mlx.mlx_ptr = mlx_init();
	if (!renderer->mlx.mlx_ptr)
	{
		log_error("Error initializing MLX");
		exit(EXIT_FAILURE);
	}
	renderer->win_width = 800;
	renderer->win_height = 600;
	ft_printf("DEBUG: mlx new window\n");
	renderer->mlx.win_ptr = mlx_new_window(renderer->mlx.mlx_ptr,
			renderer->win_width, renderer->win_height, "FdF");
	if (!renderer->mlx.win_ptr)
	{
		log_error("Error creating window");
		exit(EXIT_FAILURE);
	}
	ft_printf("DEBUG: init image\n");
	init_image(renderer);
	renderer->is_focused = 1;

	renderer->camera = malloc(sizeof(t_camera));
	if (!renderer->camera)
	{
		log_error("Error allocating memory for camera");
		exit(EXIT_FAILURE);
	}
	ft_memset(renderer->camera, 0, sizeof(t_camera));
	renderer->camera->zoom = 20;
	renderer->camera->z_height = 1.0;
	renderer->camera->x_angle = 0;
	renderer->camera->y_angle = 0;
	renderer->camera->z_angle = 0;
	renderer->camera->iso = 1;

	// Initialize map
	renderer->map = malloc(sizeof(t_map));
	if (!renderer->map)
	{
		log_error("Error allocating memory for map");
		exit(EXIT_FAILURE);
	}
	ft_memset(renderer->map, 0, sizeof(t_map));

	// Initialize mouse
	renderer->mouse = malloc(sizeof(t_mouse));
	if (!renderer->mouse)
	{
		log_error("Error allocating memory for mouse");
		exit(EXIT_FAILURE);
	}
	ft_memset(renderer->mouse, 0, sizeof(t_mouse));

	// Initialize other fields
	renderer->is_focused = 1;
	renderer->z_buffer = NULL; // Set to NULL initially; allocate later if needed
	renderer->keymode = 0;
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
