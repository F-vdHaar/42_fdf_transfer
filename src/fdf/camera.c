/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:09:07 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/24 17:45:06 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

static float	calculate_z_height(t_renderer *renderer);

int init_camera(t_renderer *renderer)
{
	renderer->camera->iso = 1;
	renderer->camera->zoom = 1.0;
	renderer->camera->x_offset = renderer->win_width / 2;
	renderer->camera->y_offset = renderer->win_height / 2;
	renderer->camera->x_angle = 0.0f;
	renderer->camera->y_angle = 0.0f;
	renderer->camera->z_angle = 0.0f;
	renderer->camera->x_scale = 1.0f;
	renderer->camera->y_scale = 1.0f;
	renderer->camera->z_scale = 1.0f;
	renderer->camera->z_height = calculate_z_height(renderer);
	return (EXIT_SUCCESS);
}

static float calculate_z_height(t_renderer *renderer)
{
	int z_range;
	int max_dim;
	float scale_x, scale_y, scale_z, scale;
	float margin = 0.8f;

	z_range = renderer->map->z_max - renderer->map->z_min;
	if (z_range <= 0)
	{
		renderer->camera->z_height = 200;
		return (200);
	}
	max_dim = renderer->map->width;
	if (renderer->map->height > max_dim)
		max_dim = renderer->map->height;
	if (z_range > max_dim)
		max_dim = z_range;
	scale_x = (float)(renderer->win_width * margin) / renderer->map->width;
	scale_y = (float)(renderer->win_height * margin) / renderer->map->height;
	scale_z = (float)(renderer->win_height * margin) / z_range;
	scale = scale_x;
	if (scale_y < scale)
		scale = scale_y;
	if (scale_z < scale)
		scale = scale_z;
	renderer->camera->z_height = z_range / scale;
	return (renderer->camera->z_height);
}

