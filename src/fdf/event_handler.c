/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:06:54 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/26 15:05:52 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// changed to mlx42
int	setup_event_hooks(t_renderer *renderer)
{
	if (!renderer || !renderer->mlx->window)
	{
		return (EXIT_FAILURE);
	}
	mlx_key_hook(renderer->mlx,
		(mlx_keyfunc)handle_mlx_keypress, (void *)renderer);
//	mlx_mouse_hook(&renderer->mlx,
//		(mlx_mousefunc)handle_mlx_mouse_press, (void *)renderer);
//	mlx_mouse_hook(&renderer->mlx,
//		(mlx_mousefunc)handle_mlx_mouse_release, (void *)renderer);
//	mlx_cursor_hook(&renderer->mlx,
//		(mlx_cursorfunc)handle_mlx_mouse_move, (void *)renderer);
	mlx_close_hook(renderer->mlx,
		(mlx_closefunc)handle_mlx_close, (void *)renderer);
	mlx_resize_hook(renderer->mlx,
		(mlx_resizefunc)handle_mlx_resize, (void *)renderer);
//	mlx_scroll_hook(&renderer->mlx,
//		(mlx_scrollfunc)handle_mlx_scroll, (void *)renderer);
	return (EXIT_SUCCESS);
}