/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:21:33 by fvon-der          #+#    #+#             */
/*   Updated: 2024/06/28 16:10:58 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fdf.h"

int	main(int argv, char **argc)
{
	int			**map;
	t_map_dim	map_dim;

	if (argv != 2)
		return (EXIT_FAILURE);
	map = parse_map(argc[1], &map_dim);
	free_map(map, map_dim.height);

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "FVDHs FDF project");
	mlx_loop(mlx);

	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
