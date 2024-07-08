/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:29:27 by fvon-der          #+#    #+#             */
/*   Updated: 2024/07/08 13:46:01 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fdf.h"

int	handle_keypress(int keycode, void *param)
{
	t_renderer	*renderer;

	renderer = (t_renderer *)param;
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT
		|| keycode == KEY_Z_TRANSLATE)
		handle_translate_key(renderer, keycode);
	else if (keycode == KEY_ZOOM_IN || keycode == KEY_ZOOM_OUT)
		handle_zoom_key(renderer, keycode);
	else if (keycode == KEY_ROTATE_LEFT || keycode == KEY_ROTATE_RIGHT
		|| keycode == KEY_ROTATE_X_UP || keycode == KEY_ROTATE_X_DOWN
		|| keycode == KEY_ROTATE_Z_LEFT || keycode == KEY_ROTATE_Z_RIGHT)
		handle_rotate_key(renderer, keycode);
	else if (keycode == KEY_STRETCH_X || keycode == KEY_STRETCH_Y
		|| keycode == KEY_STRETCH_Z)
		handle_scale_key(renderer, keycode);
	display(renderer);
	return (0);
}

void	handle_scale_key(t_renderer *renderer, int keycode)
{
	if (keycode == KEY_STRETCH_X)
		handle_scale(renderer, 1.1, 1.0, 1.0);
	else if (keycode == KEY_STRETCH_Y)
		handle_scale(renderer, 1.0, 1.1, 1.0);
	else if (keycode == KEY_STRETCH_Z)
		handle_scale(renderer, 1.0, 1.0, 1.1);
}

void	handle_rotate_key(t_renderer *renderer, int keycode)
{
	if (keycode == KEY_ROTATE_LEFT)
		handle_rotate(renderer, 0, 0.1, 0);
	else if (keycode == KEY_ROTATE_RIGHT)
		handle_rotate(renderer, 0, -0.1, 0);
	else if (keycode == KEY_ROTATE_X_UP)
		handle_rotate(renderer, 0.1, 0, 0);
	else if (keycode == KEY_ROTATE_X_DOWN)
		handle_rotate(renderer, -0.1, 0, 0);
	else if (keycode == KEY_ROTATE_Z_LEFT)
		handle_rotate(renderer, 0, 0, 0.1);
	else if (keycode == KEY_ROTATE_Z_RIGHT)
		handle_rotate(renderer, 0, 0, -0.1);
}

void	handle_zoom_key(t_renderer *renderer, int keycode)
{
	if (keycode == KEY_ZOOM_IN)
		handle_zoom(renderer, 1.1);
	else if (keycode == KEY_ZOOM_OUT)
		handle_zoom(renderer, 0.9);
}

void	handle_translate_key(t_renderer *renderer, int keycode)
{
	if (keycode == KEY_UP)
		handle_translate(renderer, 0, -10, 0);
	else if (keycode == KEY_DOWN)
		handle_translate(renderer, 0, 10, 0);
	else if (keycode == KEY_LEFT)
		handle_translate(renderer, -10, 0, 0);
	else if (keycode == KEY_RIGHT)
		handle_translate(renderer, 10, 0, 0);
	else if (keycode == KEY_Z_TRANSLATE)
		handle_translate(renderer, 0, 0, 10);
}
