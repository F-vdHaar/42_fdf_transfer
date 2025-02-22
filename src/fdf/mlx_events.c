/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:03:00 by fvon-de           #+#    #+#             */
/*   Updated: 2025/02/21 20:57:23 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_mlx_keypress(int keycode, t_renderer *renderer)
{
	t_event	event;

	event.type = EVENT_KEY_PRESS;
	event.data.key.keycode = keycode;
	enqueue_event(renderer->event_queue, event);
	return (0);
}

int	handle_mlx_close(t_renderer *renderer)
{
	t_event	event;

	event.type = EVENT_WINDOW_CLOSE;
	enqueue_event(renderer->event_queue, event);
	return (0);
}

int	handle_mlx_resize(int width, int height, t_renderer *renderer)
{
	t_event	event;

	event.type = EVENT_WINDOW_RESIZE;
	event.data.window_resize.width = width;
	event.data.window_resize.height = height;
	enqueue_event(renderer->event_queue, event);
	return (0);
}