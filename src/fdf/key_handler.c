/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:29:27 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/26 15:04:44 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> // DEBUG: For printf

static void handle_translate_key(t_renderer *renderer, int keycode);
static void handle_scale_key(t_renderer *renderer, int keycode);
static void handle_rotate_key(t_renderer *renderer, int keycode);
static void handle_zoom_key(t_renderer *renderer, int keycode);

void handle_mlx_keypress(mlx_key_data_t keydata, void *param)
{
	t_renderer *renderer = (t_renderer *)param;
	renderer->need_redraw = 1;

	printf("DEBUG: handle_mlx_keypress - Keycode: %d\n", keydata.key);

	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(renderer->mlx);
	}
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN ||
			 keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT ||
			 keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S ||
			 keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
	{
		handle_translate_key(renderer, keydata.key);
	}
	else if (keydata.key == MLX_KEY_EQUAL || keydata.key == MLX_KEY_MINUS)
	{
		handle_zoom_key(renderer, keydata.key);
	}
	else if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_E ||
			 keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
	{
		handle_rotate_key(renderer, keydata.key);
	}
	else if (keydata.key == MLX_KEY_X || keydata.key == MLX_KEY_Y ||
			 keydata.key == MLX_KEY_Z)
	{
		handle_scale_key(renderer, keydata.key);
	}
	else if (keydata.key == MLX_KEY_R) // Reset key
	{
		init_camera(renderer); // Implement this function to reset the state
		printf("DEBUG: Renderer reset.\n");
	}
	else
	{
		renderer->need_redraw = 0;
	}
	draw_window(renderer);
}

static void handle_scale_key(t_renderer *renderer, int keycode)
{
	printf("DEBUG: handle_scale_key - Keycode: %d\n", keycode);

	if (keycode == MLX_KEY_X)
	{
		printf("DEBUG: handle_scale_key - Calling handle_scale with x_scale 1.1.\n");
		handle_scale(renderer, 1.1, 1.0, 1.0);
	}
	else if (keycode == MLX_KEY_Y)
	{
		printf("DEBUG: handle_scale_key - Calling handle_scale with y_scale 1.1.\n");
		handle_scale(renderer, 1.0, 1.1, 1.0);
	}
	else if (keycode == MLX_KEY_Z)
	{
		printf("DEBUG: handle_scale_key - Calling handle_scale with z_scale 1.1.\n");
		handle_scale(renderer, 1.0, 1.0, 1.1);
	}
	else if (keycode == MLX_KEY_R)
	{
		printf("DEBUG: handle_scale_key - Resetting scale.\n");
		handle_scale(renderer, 1.0, 1.0, 1.0); // Reset to default scale factors
	}
}

static void handle_rotate_key(t_renderer *renderer, int keycode)
{
	printf("DEBUG: handle_rotate_key - Keycode: %d\n", keycode);

	if (keycode == MLX_KEY_LEFT)
	{
		printf("DEBUG: handle_rotate_key - Calling handle_rotate with y_angle 0.1.\n");
		handle_rotate(renderer, 0, 0.1, 0);
	}
	else if (keycode == MLX_KEY_RIGHT)
	{
		printf("DEBUG: handle_rotate_key - Calling handle_rotate with y_angle -0.1.\n");
		handle_rotate(renderer, 0, -0.1, 0);
	}
	else if (keycode == MLX_KEY_UP)
	{
		printf("DEBUG: handle_rotate_key - Calling handle_rotate with x_angle 0.1.\n");
		handle_rotate(renderer, 0.1, 0, 0);
	}
	else if (keycode == MLX_KEY_DOWN)
	{
		printf("DEBUG: handle_rotate_key - Calling handle_rotate with x_angle -0.1.\n");
		handle_rotate(renderer, -0.1, 0, 0);
	}
	else if (keycode == MLX_KEY_PAGE_UP)
	{
		printf("DEBUG: handle_rotate_key - Calling handle_rotate with z_angle 0.1.\n");
		handle_rotate(renderer, 0, 0, 0.1);
	}
	else if (keycode == MLX_KEY_PAGE_DOWN)
	{
		printf("DEBUG: handle_rotate_key - Calling handle_rotate with z_angle -0.1.\n");
		handle_rotate(renderer, 0, 0, -0.1);
	}
}

static void handle_zoom_key(t_renderer *renderer, int keycode)
{
	printf("DEBUG: handle_zoom_key - Keycode: %d\n", keycode);

	if (keycode == MLX_KEY_EQUAL) // Zoom in with the '+' key
	{
		handle_zoom(renderer, IN_ZOOM);
	}
	else if (keycode == MLX_KEY_MINUS) // Zoom out with the '-' key
	{
		handle_zoom(renderer, OUT_ZOOM);
	}
}

static void handle_translate_key(t_renderer *renderer, int keycode)
{
	printf("DEBUG: handle_translate_key - Keycode: %d\n", keycode);

	if (keycode == MLX_KEY_UP)
	{
		printf("DEBUG: Translating up.\n");
		handle_translate(renderer, 0, -10, 0); // Move up on the Y-axis
	}
	else if (keycode == MLX_KEY_DOWN)
	{
		printf("DEBUG: Translating down.\n");
		handle_translate(renderer, 0, 10, 0); // Move down on the Y-axis
	}
	else if (keycode == MLX_KEY_LEFT)
	{
		printf("DEBUG: Translating left.\n");
		handle_translate(renderer, -10, 0, 0); // Move left on the X-axis
	}
	else if (keycode == MLX_KEY_RIGHT)
	{
		printf("DEBUG: Translating right.\n");
		handle_translate(renderer, 10, 0, 0); // Move right on the X-axis
	}
	else if (keycode == MLX_KEY_W)
	{
		printf("DEBUG: Translating forward.\n");
		handle_translate(renderer, 0, 0, 10); // Move forward on the Z-axis
	}
	else if (keycode == MLX_KEY_S)
	{
		printf("DEBUG: Translating backward.\n");
		handle_translate(renderer, 0, 0, -10); // Move backward on the Z-axis
	}
}