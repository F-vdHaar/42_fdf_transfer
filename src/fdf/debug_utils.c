/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:45:39 by fvon-de           #+#    #+#             */
/*   Updated: 2025/02/14 14:49:55 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	debug_print_nums(char **nums)
{
	int i = 0;
	if (!nums) {
		ft_printf("DEBUG : nums is NULL\n");
		return;
	}
	
	while (nums[i]) {
		ft_printf("DEBUG : nums[%d]: \"%s\"\n", i, nums[i]);
		i++;
	}
}