/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:54:35 by fvon-der          #+#    #+#             */
/*   Updated: 2025/01/12 14:24:40 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*read_file(const char *filename, int *line_count);
static int		fill_map(int **map, t_list *lines, int width);

void	init_map(t_map **map, const char *filename)
{
	*map = (t_map *)malloc(sizeof(t_map));
	if (!*map)
	{
		log_error("Failed to allocate memory for map");
		exit(EXIT_FAILURE);
	}
	(*map)->map = parse_map(filename);
	if (!(*map)->map)
	{
		log_error("Failed to parse map");
		exit(EXIT_FAILURE);
	}
}

// Read the file and store lines in a linked list
static t_list	*read_file(const char *filename, int *line_count)
{
	int		fd;
	char	*line;
	t_list	*lines;

	lines = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_lstadd_back(&lines, ft_lstnew(line));
		(*line_count)++;
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

// Fill the map with parsed data
static int	fill_map(int **map, t_list *lines, int width)
{
	char	**nums;
	int		i;
	int		j;

	i = 0;
	while (lines)
	{
		map[i] = (int *)malloc(sizeof(int) * width);
		if (!map[i])
			return (0);
		nums = ft_split(lines->content, ' ');
		if (!nums)
			return (0);
		j = 0;
		while (j < width)
		{
			map[i][j] = ft_atoi(nums[j]);
			free(nums[j]);
			j++;
		}
		free(nums);
		i++;
		lines = lines->next;
	}
	return (1);
}

int	**parse_map(const char *filename)
{
	t_list	*lines;
	int		**map;
	int		height;
	int		width;

	height = 0;
	lines = read_file(filename, &height);
	if (!lines || height <= 0)
		return (NULL);
	width = count_words(lines->content, ' ');
	map = allocate_map(height);
	if (!map)
	{
		ft_lstclear(&lines, free);
		return (NULL);
	}
	if (!fill_map(map, lines, width))
	{
		free_map(map, height);
		ft_lstclear(&lines, free);
		return (NULL);
	}
	ft_lstclear(&lines, free);
	return (map);
}

// enders the entire map by drawing lines between adjacent points.
// Iterates over each point in the map.
// Calls draw_line to draw vertical and horizontal lines 
// between adjacent points.
void	render_map(t_renderer *renderer, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			draw_vertical_lines(renderer, map, x, y);
			draw_horizontal_lines(renderer, map, x, y);
			x++;
		}
		y++;
	}
}
