/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:21:33 by fvon-der          #+#    #+#             */
/*   Updated: 2025/01/26 16:55:46 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	render_initial(t_renderer *renderer, t_map *map);

/* 
Initialize the Environment
Cleanup Resources 
*/
int	main(int argc, char **argv)
{
	t_renderer	*renderer;
	t_map		*map;

	initialize(argc, argv, &renderer, &map);
	cleanup(renderer, map);
	return (EXIT_SUCCESS);
}

/* 
Parse the Map File
Initialise rendering and interaction Structures
Render the Map the first time
Handle User Input
mlx loop */
void	initialize(int argc, char *argv[], t_renderer **renderer, t_map **map)
{
	if (argc != 2)
	{
		ft_printf("Please enter a <map_file> for : %s \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	init_renderer(renderer);
	init_map(map, argv[1]);
	init_camera(*renderer);
	init_mouse(*renderer);
	setup_event_hooks(*renderer);
	render_initial(*renderer, *map);
	mlx_loop((*renderer)->mlx_ptr);
}

/* Draws the map onto the image buffer
Transfers the image buffer to the window.
 */
static void	render_initial(t_renderer *renderer, t_map *map)
{
	render_map(renderer, map);
	display(renderer);
}

/* 
frees allocated memory
destroys MLX objects.
 */
void	cleanup(t_renderer *renderer, t_map *map)
{
	if (renderer)
	{
		if (renderer->mlx_ptr && renderer->win_ptr)
			mlx_destroy_window(renderer->mlx_ptr, renderer->win_ptr);
		if (renderer->img_ptr)
			mlx_destroy_image(renderer->mlx_ptr, renderer->img_ptr);
		if (renderer->camera)
			free(renderer->camera);
		if (renderer->mouse)
			free(renderer->mouse);
		free(renderer);
	}
	if (map)
	{
		free_map(map->map, map->height);
		free(map);
	}
}
