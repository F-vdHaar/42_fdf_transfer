/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:15:59 by fvon-der          #+#    #+#             */
/*   Updated: 2024/06/28 16:37:49 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fdf.h"

void	print_map(int **map)
{
	int	i;
	int	j;

	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != NULL)
		{
			ft_printf("%d ", map[i][j]);
			j++;
		}
		write(1, "\n", sizeof(char));
		i++;
	}
}
