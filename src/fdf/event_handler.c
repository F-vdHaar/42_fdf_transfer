/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:06:54 by fvon-der          #+#    #+#             */
/*   Updated: 2024/07/08 13:21:09 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fdf.h"

void	setup_event_hooks(t_renderer *renderer)
{
	mlx_key_hook(renderer->win_ptr, handle_keypress, renderer);
	mlx_hook(renderer->win_ptr, 2, 0, handle_keypress, renderer);
	mlx_hook(renderer->win_ptr, 3, 0, handle_keyrelease, renderer);
	mlx_mouse_hook(renderer->win_ptr, handle_mouse_press, renderer);
	mlx_hook(renderer->win_ptr, 5, 0, handle_mouse_release, renderer);
	mlx_hook(renderer->win_ptr, 6, 0, handle_mouse_move, renderer);
}
