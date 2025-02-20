/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:09:07 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/20 12:04:42 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

static float calculate_z_height(t_renderer *renderer);
static void center_map(t_renderer *renderer, t_point *projected);

int init_camera(t_renderer *renderer) {
	renderer->camera->iso = -1;
    renderer->camera->zoom = 1;
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

t_point project_point(t_renderer *renderer, int x, int y, int z) {
    t_point projected;
    float scale;

    ft_printf("DEBUG: [project_point] Input (x = %i, y = %i, z = %i)\n", x, y, z);

    // Calculate base scale from z_height
    if (renderer->camera->z_height == 0)
        scale = 0;
    else
        scale = renderer->camera->zoom / renderer->camera->z_height;

    ft_printf("DEBUG: [project_point] Computed base scale = %f\n", scale);

    if (renderer->camera->iso == 1) {
        float temp_x = x * scale * renderer->camera->x_scale * 0.7071f;
        float temp_y = y * scale * renderer->camera->y_scale * 0.7071f;

        ft_printf("DEBUG: [project_point] Isometric temp_x = %f, temp_y = %f\n", temp_x, temp_y);

        projected.x = temp_x - temp_y;
        projected.y = ((x + y) * scale * 0.7071f) - (z * scale * renderer->camera->z_scale);

        ft_printf("DEBUG: [project_point] Isometric projected (x = %i, y = %i)\n", (int)projected.x, (int)projected.y);
    }
	else if (renderer->camera->iso == -1) {
        projected.x = x * scale * renderer->camera->x_scale;
        projected.y = y * scale * renderer->camera->y_scale;
    } 

    projected.z = z;
    center_map(renderer, &projected);

    ft_printf("DEBUG: [project_point] Final projected (x = %i, y = %i, z = %i)\n", (int)projected.x, (int)projected.y, (int)projected.z);

    return projected;
}

static float calculate_z_height(t_renderer *renderer) {
    int z_range;
    int max_dim;
    float scale_x, scale_y, scale_z, scale;
    float margin = 0.8f; // Adjust this margin as needed

    z_range = renderer->map->z_max - renderer->map->z_min;
    if (z_range <= 0) {
        ft_printf("Invalid Z-range in the map.\n");
        renderer->camera->z_height = 200;
        return (200);
    }

    // Find the largest dimension of the map
    max_dim = renderer->map->width;
    if (renderer->map->height > max_dim)
        max_dim = renderer->map->height;
    if (z_range > max_dim)
        max_dim = z_range;

    // Calculate scale factors for x, y, and z
    scale_x = (float)(renderer->win_width * margin) / renderer->map->width;
    scale_y = (float)(renderer->win_height * margin) / renderer->map->height;
    scale_z = (float)(renderer->win_height * margin) / z_range;

    // Use the smallest scale factor to ensure the map fits
    scale = scale_x;
    if (scale_y < scale)
        scale = scale_y;
    if (scale_z < scale)
        scale = scale_z;

    // Calculate z-height based on the scale
    renderer->camera->z_height = z_range / scale;

    printf("Calculated Z-height: %f\n", renderer->camera->z_height);
    return (renderer->camera->z_height);
}

static void center_map(t_renderer *renderer, t_point *projected) {
    projected->x += renderer->camera->x_offset;
    projected->y += renderer->camera->y_offset;
}
