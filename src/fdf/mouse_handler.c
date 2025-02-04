/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:08:24 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/04 02:50:18 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mouse(t_renderer *renderer)
{
	renderer->mouse = malloc(sizeof(t_mouse));
	if (!renderer->mouse)
	{
		cleanup(renderer);
		exit(EXIT_FAILURE);
	}
	renderer->mouse->is_pressed = 0;
	renderer->mouse->prev_x = 0;
	renderer->mouse->prev_y = 0;
	renderer->mouse->x = 0;
	renderer->mouse->y = 0;
	renderer->mouse->button = 0;
}

int	handle_mouse_press(int button, int x, int y, t_renderer *renderer)
{
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		handle_mouse_zoom(renderer, button);
	else if (button == MOUSE_LEFT_BUTTON)
	{
		renderer->mouse->button = button;
		renderer->mouse->prev_x = x;
		renderer->mouse->prev_y = y;
	}
	render_map(renderer);
	mlx_put_image_to_window(renderer->mlx.mlx_ptr, renderer->mlx.win_ptr,
		renderer->mlx.img_ptr, 0, 0);
	return (0);
}

int	handle_mouse_release(t_renderer *renderer)
{
	renderer->mouse->button = 0;
	render_map(renderer);
	mlx_put_image_to_window(renderer->mlx.mlx_ptr, renderer->mlx.win_ptr,
		renderer->mlx.img_ptr, 0, 0);
	return (0);
}

int	handle_mouse_move(int x, int y, t_renderer *renderer)
{
	int	dx;
	int	dy;

	dx = x - renderer->mouse->prev_x;
	dy = y - renderer->mouse->prev_y;
	if (renderer->mouse->button == MOUSE_LEFT_BUTTON)
	{
		if (renderer->keymode == ROTATE_MODE)
			handle_rotate(renderer, dy * 0.005, dx * 0.005, 0);
		else if (renderer->keymode == TRANSLATE_MODE)
			handle_translate(renderer, dx, dy);
		else if (renderer->keymode == SCALE_MODE)
			handle_scale(renderer, 1.0 + dx * 0.005, 1.0 + dy * 0.005, 1.0);
	}
	renderer->mouse->prev_x = x;
	renderer->mouse->prev_y = y;
	render_map(renderer);
	mlx_put_image_to_window(renderer->mlx.mlx_ptr, renderer->mlx.win_ptr,
		renderer->mlx.img_ptr, 0, 0);
	return (0);
}

void	handle_mouse_zoom(t_renderer *renderer, int button)
{
	if (button == MOUSE_SCROLL_UP)
		handle_zoom(renderer, 1.1);
	else if (button == MOUSE_SCROLL_DOWN)
		handle_zoom(renderer, 0.9);
	render_map(renderer);
	mlx_put_image_to_window(renderer->mlx.mlx_ptr, renderer->mlx.win_ptr,
		renderer->mlx.img_ptr, 0, 0);
}
