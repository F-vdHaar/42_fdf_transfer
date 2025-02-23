/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:53:43 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/23 13:34:36 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_translate(t_renderer *renderer, double dx, double dy, double dz)
{
		renderer->camera->x_offset += dx;
		renderer->camera->y_offset += dy;
		renderer->camera->z_height += dz;
		return (EXIT_SUCCESS);
	}

int	handle_zoom(t_renderer *renderer, double factor)
{
	renderer->camera->zoom *= factor;
	if (renderer->camera->zoom < MIN_ZOOM)
		renderer->camera->zoom = MIN_ZOOM;
	else if (renderer->camera->zoom > MAX_ZOOM)
		renderer->camera->zoom = MAX_ZOOM;
	return (EXIT_SUCCESS);
	}
	int handle_scale(t_renderer *renderer, double x_scale,
		double y_scale, double z_scale)
{
// Clamp scale factors to prevent them from becoming too small or too large
if (renderer->camera->x_scale * x_scale > MIN_SCALE && renderer->camera->x_scale * x_scale < MAX_SCALE)
	renderer->camera->x_scale *= x_scale;
if (renderer->camera->y_scale * y_scale > MIN_SCALE && renderer->camera->y_scale * y_scale < MAX_SCALE)
	renderer->camera->y_scale *= y_scale;
if (renderer->camera->z_scale * z_scale > MIN_SCALE && renderer->camera->z_scale * z_scale < MAX_SCALE)
	renderer->camera->z_scale *= z_scale;
return (EXIT_SUCCESS);
}


int	handle_rotate(t_renderer *renderer, double x_angle,
			double y_angle, double z_angle)
{
	renderer->camera->x_angle += x_angle;
	renderer->camera->y_angle += y_angle;
	renderer->camera->z_angle += z_angle;
	return (EXIT_SUCCESS);
}
