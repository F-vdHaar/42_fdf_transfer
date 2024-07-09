/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:08:24 by fvon-der          #+#    #+#             */
/*   Updated: 2024/07/09 18:33:16 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	init_mouse(t_renderer *renderer)
{
	renderer->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!renderer->mouse)
	{
		log_error("Failed to allocate memory for mouse");
		exit(EXIT_FAILURE);
	}
	renderer->mouse->button = 0;
	renderer->mouse->x = 0;
	renderer->mouse->y = 0;
	renderer->mouse->prev_x = 0;
	renderer->mouse->prev_y = 0;
}

int	handle_mouse_press(int button, int x, int y, t_renderer *renderer)
{
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		handle_zoom_mouse(renderer, button);
	else if (button == MOUSE_LEFT_BUTTON)
	{
		renderer->mouse->button = button;
		renderer->mouse->prev_x = x;
		renderer->mouse->prev_y = y;
	}
	display(renderer);
	return (0);
}

int	handle_mouse_release(int button, int x, int y, t_renderer *renderer)
{
	renderer->mouse->button = 0;
	display(renderer);
	return (0);
}

int	handle_mouse_move(int x, int y, t_renderer *renderer)
{
	int			dx;
	int			dy;

	dx = x - renderer->mouse->prev_x;
	dy = y - renderer->mouse->prev_y;
	if (renderer->mouse->button == MOUSE_LEFT_BUTTON)
	{
		if (renderer->key_states[KEY_ROTATE_MODE])
			handle_rotate(renderer, dy * 0.005, dx * 0.005, 0);
		else if (renderer->key_states[KEY_TRANSLATE_MODE])
			handle_translate(renderer, dx, dy, 0);
		else if (renderer->key_states[KEY_SCALE_MODE])
			handle_scale(renderer, 1.0 + dx * 0.005, 1.0 + dy * 0.005, 1.0);
	}
	renderer->mouse->prev_x = x;
	renderer->mouse->prev_y = y;
	display(renderer);
	return (0);
}

void	handle_zoom_mouse(t_renderer *renderer, int button)
{
	if (button == MOUSE_SCROLL_UP)
		handle_zoom(renderer, 1.1);
	else if (button == MOUSE_SCROLL_DOWN)
		handle_zoom(renderer, 0.9);
	display(renderer);
}
