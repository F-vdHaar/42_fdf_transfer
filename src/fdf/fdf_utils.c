/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:25:03 by fvon-der          #+#    #+#             */
/*   Updated: 2025/01/11 16:31:41 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// mlx_pixel_put is quite slow
// as it push the pixel instantly to the window 
// (without waiting for the frame to be entirely rendered)
// so fast_mlx_pixel_put has a buffer
/* void	fast_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = (unsigned int*) color;
} */
