/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:21:33 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/04 02:51:33 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	render_initial(t_renderer *renderer);

int	main(int argc, char **argv)
{
	t_renderer	*renderer;
	t_map		*map;

	initialize(argc, argv, &renderer, &map);
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
	init_renderer(*renderer);
	if (!*renderer)
		exit(EXIT_FAILURE);
	init_map(map, argv[1]);
	if (!*map)
	{
		cleanup(*renderer);
		exit(EXIT_FAILURE);
	}
	init_camera(*renderer);
	init_mouse(*renderer);
	setup_event_hooks(*renderer);
	render_initial(*renderer);
	mlx_loop((*renderer)->mlx.mlx_ptr);
}

static void	render_initial(t_renderer *renderer)
{
	render_map(renderer);
	mlx_put_image_to_window(renderer->mlx.mlx_ptr, renderer->mlx.win_ptr,
		renderer->mlx.img_ptr, 0, 0);
}
