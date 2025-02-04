/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:09:07 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/04 02:18:43 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_camera(t_renderer *renderer)
{
	renderer->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!renderer->camera)
	{
		log_error("Failed to allocate memory for camera");
		cleanup(renderer);
		exit(EXIT_FAILURE);
	}
	renderer->camera->zoom = 20;
	renderer->camera->x_angle = 0;
	renderer->camera->y_angle = 0;
	renderer->camera->z_angle = 0;
	renderer->camera->z_height = 1.0f;
	renderer->camera->x_offset = renderer->win_width / 2;
	renderer->camera->y_offset = renderer->win_height / 2;
	renderer->camera->iso = 1;
}

void	reset_camera(t_renderer *renderer)
{
	renderer->camera->zoom = 1.0;
	renderer->camera->x_offset = 0;
	renderer->camera->y_offset = 0;
	renderer->camera->x_angle = 0;
	renderer->camera->y_angle = 0;
	renderer->camera->z_angle = 0;
	renderer->camera->x_scale = 1.0;
	renderer->camera->y_scale = 1.0;
	renderer->camera->z_scale = 1.0;
}

t_point	project_point(t_renderer *renderer, int x, int y, int z)
{
	t_point	projected;
	float	scale;

	scale = renderer->camera->zoom / (z + renderer->camera->z_height);
	projected.x = (x - renderer->camera->x_offset) * scale;
	projected.y = (y - renderer->camera->y_offset) * scale;
	projected.z = z;
	projected.x += renderer->win_width / 2;
	projected.y += renderer->win_height / 2;
	rotate_point(&projected, renderer->camera);
	return (projected);
}
