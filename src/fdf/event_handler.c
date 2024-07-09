/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:06:54 by fvon-der          #+#    #+#             */
/*   Updated: 2024/07/09 18:32:42 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	setup_event_hooks(t_renderer *renderer)
{
	mlx_key_hook(renderer->win_ptr, handle_keypress, renderer);
	mlx_hook(renderer->win_ptr, 2, 0, handle_keypress, renderer);
	mlx_hook(renderer->win_ptr, 3, 0, handle_keyrelease, renderer);
	mlx_mouse_hook(renderer->win_ptr, handle_mouse_press, renderer);
	mlx_hook(renderer->win_ptr, 5, 0, handle_mouse_release, renderer);
	mlx_hook(renderer->win_ptr, 6, 0, handle_mouse_move, renderer);
	mlx_hook(renderer->win_ptr, 9, 0, handle_resize, renderer);
	mlx_hook(renderer->win_ptr, 21, 0, handle_focus_in, renderer);
	mlx_hook(renderer->win_ptr, 22, 0, handle_focus_out, renderer);
}
