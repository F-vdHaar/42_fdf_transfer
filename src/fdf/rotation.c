/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:37:02 by fvon-de           #+#    #+#             */
/*   Updated: 2025/02/24 18:04:44 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

static void	create_rotation_matrices(t_renderer *renderer,
	float rot_x[3][3], float rot_y[3][3], float rot_z[3][3]);
	
t_point	rotate_point(t_renderer *renderer, t_point point)
{
	float	rot_x[3][3];
	float	rot_y[3][3];
	float	rot_z[3][3];
	t_point	rotated;

	create_rotation_matrices(renderer, rot_x, rot_y, rot_z);
	rotated.x = point.x * rot_z[0][0] + point.y * rot_z[0][1] + point.z * rot_z[0][2];
	rotated.y = point.x * rot_z[1][0] + point.y * rot_z[1][1] + point.z * rot_z[1][2];
	rotated.z = point.x * rot_z[2][0] + point.y * rot_z[2][1] + point.z * rot_z[2][2];
	point = rotated;
	rotated.x = point.x * rot_y[0][0] + point.y * rot_y[0][1] + point.z * rot_y[0][2];
	rotated.y = point.x * rot_y[1][0] + point.y * rot_y[1][1] + point.z * rot_y[1][2];
	rotated.z = point.x * rot_y[2][0] + point.y * rot_y[2][1] + point.z * rot_y[2][2];
	point = rotated;
	rotated.x = point.x * rot_x[0][0] + point.y * rot_x[0][1] + point.z * rot_x[0][2];
	rotated.y = point.x * rot_x[1][0] + point.y * rot_x[1][1] + point.z * rot_x[1][2];
	rotated.z = point.x * rot_x[2][0] + point.y * rot_x[2][1] + point.z * rot_x[2][2];
	return (rotated);
}

static void	create_rotation_matrices(t_renderer *renderer,
	float rot_x[3][3], float rot_y[3][3], float rot_z[3][3])
{
	float	c;
	float	s;

	c = cos(renderer->camera->x_angle);
	s = sin(renderer->camera->x_angle);
	rot_x[0][0] = 1; rot_x[0][1] = 0; rot_x[0][2] = 0;
	rot_x[1][0] = 0; rot_x[1][1] = c; rot_x[1][2] = -s;
	rot_x[2][0] = 0; rot_x[2][1] = s; rot_x[2][2] = c;
	c = cos(renderer->camera->y_angle);
	s = sin(renderer->camera->y_angle);
	rot_y[0][0] = c; rot_y[0][1] = 0; rot_y[0][2] = s;
	rot_y[1][0] = 0; rot_y[1][1] = 1; rot_y[1][2] = 0;
	rot_y[2][0] = -s; rot_y[2][1] = 0; rot_y[2][2] = c;
	c = cos(renderer->camera->z_angle);
	s = sin(renderer->camera->z_angle);
	rot_z[0][0] = c; rot_z[0][1] = -s; rot_z[0][2] = 0;
	rot_z[1][0] = s; rot_z[1][1] = c; rot_z[1][2] = 0;
	rot_z[2][0] = 0; rot_z[2][1] = 0; rot_z[2][2] = 1;
}
