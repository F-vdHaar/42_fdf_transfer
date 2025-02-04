/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:53:43 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/04 02:09:00 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_translate(t_renderer *renderer, double dx, double dy)
{
	renderer->camera->x_offset += dx;
	renderer->camera->y_offset += dy;
}

void	handle_zoom(t_renderer *renderer, double factor)
{
	renderer->camera->zoom *= factor;
	if (renderer->camera->zoom < MIN_ZOOM)
		renderer->camera->zoom = MIN_ZOOM;
	else if (renderer->camera->zoom > MAX_ZOOM)
		renderer->camera->zoom = MAX_ZOOM;
}

void	handle_scale(t_renderer *renderer, double x_scale,
			double y_scale, double z_scale)
{
	renderer->camera->x_scale *= x_scale;
	renderer->camera->y_scale *= y_scale;
	renderer->camera->z_scale *= z_scale;
}

void	handle_rotate(t_renderer *renderer, double x_angle,
			double y_angle, double z_angle)
{
	renderer->camera->x_angle += x_angle;
	renderer->camera->y_angle += y_angle;
	renderer->camera->z_angle += z_angle;
}
