/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:54:35 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/15 18:35:51 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*read_file(const char *filename, int *line_count);
static int		fill_map(t_map *map, t_list *lines);

void	init_map(t_map **map, const char *filename)
{
	*map = (t_map *)malloc(sizeof(t_map));
	if (!*map)
	{
		log_error("Failed to allocate memory for map");
		exit(EXIT_FAILURE);
	}
	(*map)->file_content = read_file(filename, &(*map)->height);
	if (!(*map)->file_content)
	{
		log_error("Failed to read map file");
		free(*map);
		exit(EXIT_FAILURE);
	}
	(*map)->width = count_words(((char *)(*map)->file_content->content), ' ');
	(*map)->grid = allocate_map((*map)->height, (*map)->width);
	if (!(*map)->grid || !fill_map(*map, (*map)->file_content))
	{
		log_error("Failed to parse map");
		free_map(*map);
		exit(EXIT_FAILURE);
	}
	find_z_bounds(*map);
}

static t_list	*read_file(const char *filename, int *line_count)
{
	int		fd;
	char	*line;
	t_list	*lines;

	lines = NULL;
	*line_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = ft_trim(get_next_line(fd), "\n");
	while (line != NULL)
	{
		ft_lstadd_back(&lines, ft_lstnew(line));
		(*line_count)++;
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

static int	fill_map(t_map *map, t_list *lines)
{
	char	**nums;
	int 	i;
	int 	j;

	i = 0;
	while (i < map->height)
	{
		nums = ft_split(lines->content, ' ');
		if (!nums)
			return (0); 
		j = 0;
		while (j < map->width)
		{
			map->grid[i][j] = ft_atoi(nums[j]);
			free(nums[j]);
			j++;
		}
		free(nums);
		i++;
		lines = lines->next;
	}
	return (1);
}
