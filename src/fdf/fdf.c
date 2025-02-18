/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:21:33 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/18 23:35:44 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	draw_window(t_renderer *renderer);


int main(int argc, char **argv)
{
	t_renderer	*renderer = NULL;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file>\n", argv[0]);
		return EXIT_FAILURE;
	}
	if (!(renderer = malloc(sizeof(t_renderer)))) {
		log_error("Error: Failed to allocate memory for renderer");
		return EXIT_FAILURE;
	}
	ft_memset(renderer, 0, sizeof(t_renderer));
	if (initialize(renderer, argv[1]) == EXIT_FAILURE)
	{ 
		free(renderer); // Free if init fails
		return EXIT_FAILURE;
	}
	draw_window(renderer);
	mlx_loop(renderer->mlx.mlx_ptr);
	cleanup(renderer);
	return (EXIT_SUCCESS);
}

int initialize(t_renderer *renderer, char *filename)
{
	renderer->map = malloc(sizeof(t_map));
	renderer->camera = malloc(sizeof(t_camera));
	renderer->mouse = malloc(sizeof(t_mouse));
	if (!renderer->map || !renderer->camera || !renderer->mouse) {
		log_error("Error: Failed to allocate memory for one or more renderer elements");
		cleanup(renderer);
		return EXIT_FAILURE;
	}
	ft_memset(renderer->map, 0, sizeof(t_map));
	ft_memset(renderer->camera, 0, sizeof(t_camera));
	ft_memset(renderer->mouse, 0, sizeof(t_mouse));
	if (init_renderer(renderer) == EXIT_FAILURE || 
	init_map(renderer, filename) == EXIT_FAILURE ||
	init_camera(renderer) == EXIT_FAILURE ||
	init_mouse(renderer) == EXIT_FAILURE ||
	setup_event_hooks(renderer) == EXIT_FAILURE)
	{
		log_error("Error: Failed to initialize one or more renderer elements");
		cleanup(renderer);
		return EXIT_FAILURE;
	}
	mlx_loop_hook(renderer->mlx.mlx_ptr, (int (*)(void *))draw_window, renderer);
	return EXIT_SUCCESS;
}


static int	draw_window(t_renderer *renderer)
{
	//debug_render_grid(renderer); 
	render_map(renderer);
	//draw_pixel(renderer, 200, 200, 0xFF0000);
	mlx_put_image_to_window(renderer->mlx.mlx_ptr, renderer->mlx.win_ptr,
		renderer->mlx.img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}
