/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:21:33 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/15 18:47:43 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	render_initial(t_renderer *renderer);

int	main(int argc, char **argv)
{
	t_renderer	*renderer;
	t_map		*map;

	ft_printf("DEBUG: initalize\n");
	initialize(argc, argv, &renderer, &map);
	ft_printf("DEBUG: cleanup\n" );
	cleanup(renderer);
	return (EXIT_SUCCESS);
}

void	initialize(int argc, char *argv[], t_renderer **renderer, t_map **map)
{
	if (argc != 2)
	{
		ft_printf("Please enter a <map_file> for : %s \n", argv[0]);
		exit(EXIT_FAILURE);
	}

	ft_printf("DEBUG: init render\n");

	// Allocate memory for renderer (since it's a pointer)
	*renderer = malloc(sizeof(t_renderer));
	if (!*renderer)
	{
		log_error("Failed to allocate memory for renderer");
		exit(EXIT_FAILURE);
	}

	ft_memset(*renderer, 0, sizeof(t_renderer));  // Initialize struct memory
	init_renderer(*renderer);  // Pass the allocated struct

	if (!*renderer)
		exit(EXIT_FAILURE);

	ft_printf("DEBUG: init map\n");
	init_map(map, argv[1]);  // Initialize map
	if (!*map)
	{
		cleanup(*renderer);
		exit(EXIT_FAILURE);
	}
	(*renderer)->map = *map;
	ft_printf("DEBUG: init camera\n");
	init_camera(*renderer);  // Initialize camera
	ft_printf("DEBUG: init mouse\n");
	init_mouse(*renderer);   // Initialize mouse
	ft_printf("DEBUG: setup event hook\n");
	setup_event_hooks(*renderer);
	ft_printf("DEBUG: render initial\n");
	render_initial(*renderer);
	ft_printf("DEBUG: First pixel value = %#x\n", *(int *)(*renderer)->mlx.img_data);
	ft_printf("DEBUG: mlx loop\n");
	mlx_loop((*renderer)->mlx.mlx_ptr);
}


static void	render_initial(t_renderer *renderer)
{
	render_map(renderer);
	//draw_pixel(renderer, 200, 200, 0xFF0000);
	mlx_put_image_to_window(renderer->mlx.mlx_ptr, renderer->mlx.win_ptr,
		renderer->mlx.img_ptr, 0, 0);
}
