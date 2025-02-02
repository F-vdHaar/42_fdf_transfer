/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:09:07 by fvon-der          #+#    #+#             */
/*   Updated: 2025/01/11 16:24:38 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_camera(t_renderer *renderer)
{
	renderer->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!renderer->camera)
	{
		log_error("Failed to allocate memory for camera");
		exit(EXIT_FAILURE);
	}
	renderer->camera->zoom = 20;
	renderer->camera->x_angle = 0;
	renderer->camera->y_angle = 0;
	renderer->camera->z_angle = 0;
	renderer->camera->z_height = 1.0f;
	renderer->camera->x_offset = 400;
	renderer->camera->y_offset = 300;
	renderer->camera->iso = 1;
}
