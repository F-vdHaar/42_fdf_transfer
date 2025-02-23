/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:01:23 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/23 12:29:17 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rotate_point(t_point *point, t_camera *camera)
{
	double	temp_x;
	double	temp_y;
	double	temp_z;

	temp_y = point->y * cos(camera->x_angle) - point->z * sin(camera->x_angle);
	temp_z = point->y * sin(camera->x_angle) + point->z * cos(camera->x_angle);
	point->y = temp_y;
	point->z = temp_z;
	temp_x = point->x * cos(camera->y_angle) + point->z * sin(camera->y_angle);
	temp_z = -point->x * sin(camera->y_angle) + point->z * cos(camera->y_angle);
	point->x = temp_x;
	point->z = temp_z;
	temp_x = point->x * cos(camera->z_angle) - point->y * sin(camera->z_angle);
	temp_y = point->x * sin(camera->z_angle) + point->y * cos(camera->z_angle);
	point->x = temp_x;
	point->y = temp_y;
	return (EXIT_SUCCESS);
}
