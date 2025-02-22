/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:25:23 by fvon-de           #+#    #+#             */
/*   Updated: 2025/02/22 09:16:51 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int handle_close(t_renderer *renderer) {
    if (!renderer || !renderer->mlx.mlx_ptr || !renderer->mlx.win_ptr) {
        return (EXIT_FAILURE);
    }
//    mlx_destroy_window(renderer->mlx.mlx_ptr, renderer->mlx.win_ptr);
    cleanup(renderer);
    renderer = NULL;
    exit(EXIT_SUCCESS);
}

int handle_resize(int width, int height, t_renderer *renderer) {
    if (!renderer || !renderer->mlx.mlx_ptr || !renderer->mlx.win_ptr) {
        return (EXIT_FAILURE);
    }

    // Update renderer dimensions:
    renderer->win_width = width;
    renderer->win_height = height;

    // Recreate image buffer:
    if (renderer->mlx.img_ptr) {
        mlx_destroy_image(renderer->mlx.mlx_ptr, renderer->mlx.img_ptr);
    }
    renderer->mlx.img_ptr = mlx_new_image(renderer->mlx.mlx_ptr, width, height);
    if (!renderer->mlx.img_ptr) {
        return (EXIT_FAILURE); // Handle error
    }
    renderer->mlx.img_data = mlx_get_data_addr(renderer->mlx.img_ptr, &renderer->mlx.bits_per_pixel, &renderer->mlx.line_length, &renderer->mlx.endian);

    // Redraw the map:
    draw_window(renderer);
    return (EXIT_SUCCESS);
}