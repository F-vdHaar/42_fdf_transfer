/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:06:54 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/22 07:47:31 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	setup_event_hooks(t_renderer *renderer)
{
	if (!renderer || !renderer->mlx.win_ptr || !renderer->event_queue)
	{
		return (EXIT_FAILURE);
	}
	renderer->event_queue->head = 0;
	renderer->event_queue->tail = 0;
	mlx_key_hook(renderer->mlx.win_ptr, handle_mlx_keypress, renderer);
	mlx_mouse_hook(renderer->mlx.win_ptr, handle_mlx_mouse_press, renderer);
	mlx_hook(renderer->mlx.win_ptr, 5, 0, handle_mlx_mouse_release, renderer);
	mlx_hook(renderer->mlx.win_ptr, 6, 0, handle_mlx_mouse_move, renderer);
	mlx_hook(renderer->mlx.win_ptr, 17, 0, handle_mlx_close, renderer);
	mlx_hook(renderer->mlx.win_ptr, 25, (1L << 18), handle_mlx_resize, renderer);
    return (EXIT_SUCCESS);
}


//Circular queue -> very efficient for fixed size buffer eg event queue 
void enqueue_event(t_event_queue *event_queue, t_event event)
{

    int next_tail = (event_queue->tail + 1) % MAX_EVENTS;

    if (next_tail == event_queue->head) {
        log_error("Error: Event queue is full\n");       
        return;
    }
    event_queue->queue[event_queue->tail] = event;
    event_queue->tail = next_tail;
}



void	process_events(t_event_queue *event_queue, t_renderer *renderer)
{
	t_event	event;

	while (event_queue->head != event_queue->tail)
	{
		event = event_queue->queue[event_queue->head];
		event_queue->head = (event_queue->head + 1) % MAX_EVENTS;
		if (event.type == EVENT_KEY_PRESS)
		{
			printf("DEBUG: Key press: %d\n", event.data.key.keycode);
		}
		else if (event.type == EVENT_MOUSE_PRESS)
		{
			printf("DEBUG: Mouse press: button=%d, x=%d, y=%d\n",
				   event.data.mouse.button, event.data.mouse.x, event.data.mouse.y);
		}
		else if (event.type == EVENT_MOUSE_RELEASE)
		{
			printf("DEBUG: Mouse release: button=%d, x=%d, y=%d\n",
				   event.data.mouse.button, event.data.mouse.x, event.data.mouse.y);
		}
		else if (event.type == EVENT_WINDOW_CLOSE)
		{
			printf("DEBUG: Window close event\n");
			handle_close(renderer);
		}
		else if (event.type == EVENT_WINDOW_RESIZE)
		{
			printf("DEBUG: Window resize event\n");
			handle_resize(event.data.window_resize.width,
						  event.data.window_resize.height, renderer);
		}
	}
}

int process_events_wrapper(void *renderer_ptr)
{
    t_renderer *renderer = (t_renderer *)renderer_ptr;
    process_events(renderer->event_queue, renderer);
    return (0);
}
