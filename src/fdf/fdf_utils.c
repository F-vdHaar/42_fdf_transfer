/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:25:03 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/18 20:56:51 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	cleanup_mlx(t_mlx *mlx);
static void	cleanup_renderer(t_renderer *renderer);

static void	cleanup_mlx(t_mlx *mlx)
{
	if (mlx->mlx_ptr && mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	if (mlx->mlx_ptr)
		free(mlx->mlx_ptr);
}

static void	cleanup_renderer(t_renderer *renderer)
{
	if (renderer)
	{
		cleanup_mlx(&renderer->mlx);
		free(renderer->camera);
		free(renderer->z_buffer);
		free(renderer);
	}
}

int	cleanup(t_renderer *renderer)
{
	free_map(renderer->map);
	cleanup_renderer(renderer);
    return (EXIT_SUCCESS);
}
