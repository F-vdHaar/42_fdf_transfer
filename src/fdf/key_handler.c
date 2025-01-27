/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:29:27 by fvon-der          #+#    #+#             */
/*   Updated: 2025/01/12 13:42:53 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	handle_translate_key(t_renderer *renderer, int keycode);
static void	handle_scale_key(t_renderer *renderer, int keycode);
static void	handle_rotate_key(t_renderer *renderer, int keycode);
static void	handle_zoom_key(t_renderer *renderer, int keycode);

int	handle_keypress(int keycode, t_renderer *renderer)
{
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

static void	handle_scale_key(t_renderer *renderer, int keycode)
{
	if (keycode == KEY_STRETCH_X)
		handle_scale(renderer, 1.1, 1.0, 1.0);
	else if (keycode == KEY_STRETCH_Y)
		handle_scale(renderer, 1.0, 1.1, 1.0);
	else if (keycode == KEY_STRETCH_Z)
		handle_scale(renderer, 1.0, 1.0, 1.1);
}

static void	handle_rotate_key(t_renderer *renderer, int keycode)
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

static void	handle_zoom_key(t_renderer *renderer, int keycode)
{
	if (keycode == KEY_ZOOM_IN)
		handle_zoom(renderer, 1.1);
	else if (keycode == KEY_ZOOM_OUT)
		handle_zoom(renderer, 0.9);
}

static void	handle_translate_key(t_renderer *renderer, int keycode)
{
	if (keycode == KEY_UP)
		handle_translate(renderer, 0, -10);
	else if (keycode == KEY_DOWN)
		handle_translate(renderer, 0, 10);
	else if (keycode == KEY_LEFT)
		handle_translate(renderer, -10, 0);
	else if (keycode == KEY_RIGHT)
		handle_translate(renderer, 10, 0);
	else if (keycode == KEY_Z_TRANSLATE)
		handle_translate(renderer, 0, 10);
}
