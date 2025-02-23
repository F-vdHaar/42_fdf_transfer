/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:25:03 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/23 12:28:11 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	cleanup_mlx(t_mlx *mlx);
static void	cleanup_renderer(t_renderer *renderer);


// If Platrom mlx issues arise it could arise from here  
// its not implemented in all mlx versions
// omitting it causes a tiny memory leak
// if (mlx->mlx_ptr) {
// 	mlx_destroy_display(mlx->mlx_ptr);
// 	free(mlx->mlx_ptr);
// }
static void	cleanup_mlx(t_mlx *mlx)
{
	if (mlx) {
		ft_printf("DEBUG : [cleanup_mlx] : mlx_ptr = %p, win_ptr = %p\n", mlx->mlx_ptr, mlx->win_ptr);

		if (mlx->mlx_ptr && mlx->win_ptr) {
			if(mlx->mlx_ptr && mlx->win_ptr){
				mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
			}
		}
		if (mlx->img_ptr) {
			mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		}
	}
}
//mlx is a struct directly inside the t_renderer struct, it is freed when the renderer struct is freed. Therefore, no additional free is needed.
static void	cleanup_renderer(t_renderer *renderer)
{
	if (renderer)
	{
		cleanup_mlx(&renderer->mlx);
		free(renderer->camera);
		renderer->camera = NULL;
		free(renderer->z_buffer);
		renderer->z_buffer = NULL;
		free(renderer);
	}
}

int	cleanup(t_renderer *renderer)
{
	if (renderer)
	{
		free_map(renderer->map);
		renderer->map = NULL;
		cleanup_renderer(renderer);
	}
	return (EXIT_SUCCESS);
}
