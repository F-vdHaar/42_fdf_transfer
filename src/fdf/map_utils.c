/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:55:06 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/23 12:28:32 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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

int	**allocate_map(int height, int width)
{
	int	**map;
	int	i;

	map = (int **)malloc(sizeof(int *) * height);
	if (!map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = (int *)malloc(sizeof(int) * width);
		if (!map[i])
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

int	free_map(t_map *map)
{
	int	i;

	if (map)
	{
		if (map->grid)
		{
			i = 0;
			while (i < map->height)
			{
				free(map->grid[i]);
				i++;
			}
			free(map->grid);
		}
		if (map->color)
		{
			i = 0;
			while (i < map->height)
			{
				free(map->color[i]);
				i++;
			}
			free(map->color);
		}
		free(map);
	}
	return (EXIT_SUCCESS);
}

int	find_z_bounds(t_map *map)
{
	int	i;
	int	j;

	map->z_min = INT_MAX;
	map->z_max = INT_MIN;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] < map->z_min)
				map->z_min = map->grid[i][j];
			if (map->grid[i][j] > map->z_max)
				map->z_max = map->grid[i][j];
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
