/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:55:06 by fvon-der          #+#    #+#             */
/*   Updated: 2024/07/09 18:33:07 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"
// Count the number of words in a string using a delimiter
int	count_words(const char *str, char delimiter)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == delimiter)
			i++;
		if (str[i] && str[i] != delimiter)
		{
			count++;
			while (str[i] && str[i] != delimiter)
				i++;
		}
	}
	return (count);
}

// Allocate memory for the map based on height
static int	**allocate_map(int height)
{
	int	**map;

	map = (int **)malloc(sizeof(int *) * height);
	if (!map)
		return (NULL);
	return (map);
}
