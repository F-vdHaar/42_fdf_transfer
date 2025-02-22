/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:28:06 by fvon-de           #+#    #+#             */
/*   Updated: 2025/02/21 17:20:55 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_mlx_mouse_press(int button, int x, int y, t_renderer *renderer)
{
	t_event	event;

	event.type = EVENT_MOUSE_PRESS;
	event.data.mouse.button = button;
	event.data.mouse.x = x;
	event.data.mouse.y = y;
	enqueue_event(renderer->event_queue, event);
	return (0);
}

int	handle_mlx_mouse_release(int button, int x, int y, t_renderer *renderer)
{
	t_event	event;

	event.type = EVENT_MOUSE_RELEASE;
	event.data.mouse.button = button;
	event.data.mouse.x = x;
	event.data.mouse.y = y;
	enqueue_event(renderer->event_queue, event);
	return (0);
}

// does nothing for now
int	handle_mlx_mouse_move(int x, int y, t_renderer *renderer)
{
	t_event	event;

	event.type = EVENT_MOUSE_MOVE;
	event.data.mouse.x = x;
	event.data.mouse.y = y;
	//enqueue_event(renderer->event_queue, event);
	return (0);
}
