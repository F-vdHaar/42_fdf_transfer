/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:06:54 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/20 12:35:03 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	setup_event_hooks(t_renderer *renderer)
{
	mlx_key_hook(renderer->mlx.win_ptr, handle_keypress, renderer);
	mlx_hook(renderer->mlx.win_ptr, 2, 0, handle_keypress, renderer);
	mlx_mouse_hook(renderer->mlx.win_ptr, handle_mouse_press, renderer);
	mlx_hook(renderer->mlx.win_ptr, 5, 0, handle_mouse_release, renderer);
	mlx_hook(renderer->mlx.win_ptr, 6, 0, handle_mouse_move, renderer);
	mlx_hook(renderer->mlx.win_ptr, 17, 0, handle_close, renderer);
    return (EXIT_SUCCESS);
}

int	handle_close(t_renderer *renderer)
{
	mlx_destroy_window(renderer->mlx.mlx_ptr, renderer->mlx.win_ptr);
	cleanup(renderer);
	exit(0);
    return (EXIT_SUCCESS);
}
