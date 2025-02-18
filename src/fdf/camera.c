/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:09:07 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/18 23:57:02 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	calculate_z_height(t_renderer *renderer);


int init_camera(t_renderer *renderer)
{
    renderer->camera->zoom = 1;
    renderer->camera->x_angle = 0.0f; 
    renderer->camera->y_angle = 0.0f;
    renderer->camera->z_angle = 0.0f;
    renderer->camera->x_scale = 1.0f;
    renderer->camera->y_scale = 1.0f;
    renderer->camera->z_scale = 1.0f;
    renderer->camera->z_height = calculate_z_height(renderer);
    renderer->camera->x_offset = 0; //renderer->win_width / 2;
    renderer->camera->y_offset = 0; // renderer->win_height / 2;
    renderer->camera->iso = -1;

    return (EXIT_SUCCESS);
}

int reset_camera(t_renderer *renderer)
{
    renderer->camera->zoom = 1;
    renderer->camera->x_angle = 0.0f;
    renderer->camera->y_angle = 0.0f;
    renderer->camera->z_angle = 0.0f;
    renderer->camera->x_scale = 1.0f;
    renderer->camera->y_scale = 1.0f;
    renderer->camera->z_scale = 1.0f;
    renderer->camera->z_height = calculate_z_height(renderer);
    renderer->camera->x_offset = renderer->win_width / 2;
    renderer->camera->y_offset = renderer->win_height / 2;
    return (EXIT_SUCCESS);
}


// cos(45) =sin(45) 0.7071,
t_point project_point(t_renderer *renderer, int x, int y, int z)
{
    t_point projected;
    float scale;
    float top_down_scale = 50.0f; // This is  for debugging with top own view

    ft_printf("DEBUG: [project_point] Input (x = %i, y = %i, z = %i)\n", x, y, z);

    // Check if the point should be scaled (camera's z-height)
    if (z + renderer->camera->z_height == 0)
        scale = 0;
    else 
        scale = renderer->camera->zoom / (z + renderer->camera->z_height);

    ft_printf("DEBUG: [project_point] Computed scale = %\n", scale);

    if (renderer->camera->iso)
    {
        float temp_x = (x - renderer->camera->x_offset) * scale * 0.7071;
        float temp_y = (y - renderer->camera->y_offset) * scale * 0.7071;

        ft_printf("DEBUG: [project_point] Isometric temp_x = %f, temp_y = %f\n", temp_x, temp_y);

        projected.x = temp_x - temp_y;
        projected.y = ((x + y) * scale * 0.7071) - (z * scale);

        ft_printf("DEBUG: [project_point] Isometric projected (x = %i, y = %i)\n",
                  (int)projected.x, (int)projected.y);
    }
    else if (renderer->camera->iso == -1)
    {
        projected.x = x * top_down_scale;
        projected.y = y * top_down_scale;
    }
    else
    {
        float temp_x = (x - renderer->camera->x_offset) * scale;
        float temp_y = (y - renderer->camera->y_offset) * scale;
        float temp_z_x = cos(renderer->camera->x_angle) * z * scale;
        float temp_z_y = sin(renderer->camera->y_angle) * z * scale;

        printf("DEBUG: [project_point] Non-Iso temp_x = %f, temp_y = %f, temp_z_x = %f, temp_z_y = %f\n",
                  temp_x, temp_y, temp_z_x, temp_z_y);

        projected.x = temp_x + temp_z_x;
        projected.y = temp_y + temp_z_y;

        ft_printf("DEBUG: [project_point] Non-Iso projected (x = %i, y = %i)\n",
                  (int)projected.x, (int)projected.y);
    }

    projected.z = z;

    ft_printf("DEBUG: [project_point] Final projected (x = %i, y = %i, z = %i)\n",
              (int)projected.x, (int)projected.y, (int)projected.z);

    return projected;
}

static int	calculate_z_height(t_renderer *renderer)
{
	int	z_range;
	int	height;

	z_range = renderer->map->z_max - renderer->map->z_min;
	if (z_range <= 0)
	{
		ft_printf("Invalid Z-range in the map.");
		height = renderer->camera->z_height = 200;
	}
	height = z_range * (renderer->camera->z_scale);
	renderer->camera->z_height = height;
	printf("Calculated Z-height: %i\n", height);
	return (height);
}
