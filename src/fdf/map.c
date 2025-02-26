/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:54:35 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/26 15:46:27 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*read_file(const char *filename, int *line_count);
static int		fill_map(t_map *map, t_list *lines);

int	init_map(t_renderer *renderer, const char *filename)
{
	t_map * map;

	map = renderer->map;
	if (!map)
	{
		log_error("Failed to allocate memory for map");
		exit(EXIT_FAILURE);
	}
	(map)->file_content = read_file(filename, &(map)->height);
	if (!(map)->file_content)
	{
		log_error("Failed to read map file");
		cleanup(renderer);
		exit(EXIT_FAILURE);
	}
	(map)->width = count_words(((char *)(map)->file_content->content), ' ');
	(map)->grid = allocate_map((map)->height, (map)->width);
	(map)->color = allocate_map(map->height, map->width);
	if (!(map)->grid || (fill_map(map, (map)->file_content) == EXIT_FAILURE))
	{
		log_error("Failed to parse map");
		free_map(map);
		exit(EXIT_FAILURE);
	}
	find_z_bounds(map);
	renderer->map = map;
	return (EXIT_SUCCESS);
}

static t_list *read_file(const char *filename, int *line_count) {
	int fd;
	char *line;
	char *trimmed_line; // Store the trimmed line
	t_list *lines;

	lines = NULL;
	*line_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd); // Get the raw line
	while (line != NULL) {
		trimmed_line = ft_trim(line, "\n"); // Trim the line
		free(line); // Free the original line from get_next_line
		ft_lstadd_back(&lines, ft_lstnew(trimmed_line)); // Add the trimmed line to the list
		(*line_count)++;
		line = get_next_line(fd); // Get the next line
	}
	close(fd);
	return (lines);
}

static int fill_map(t_map *map, t_list *lines) {
	char **nums;
	int i;
	int j;
	char *comma;

	i = 0;
	while (i < map->height) {
		nums = ft_split(lines->content, ' ');
		if (!nums)
			return EXIT_FAILURE;

		j = 0;
		while (j < map->width) {
			comma = ft_strchr(nums[j], ',');
			if (comma) {
				*comma = '\0'; // Split the string
				map->grid[i][j] = ft_atoi(nums[j]);
				if(comma + 3){ //Added check here.
					map->color[i][j] = ft_atoi_base(comma + 3, "0123456789ABCDEF");
				} else {
					map->color[i][j] = 0; // or some default color, or error handling
				}

			} else {
				map->grid[i][j] = ft_atoi(nums[j]);
				map->color[i][j] = 0xFFFFFF;
			}
			free(nums[j]);
			j++;
		}
		free(nums);
		i++;
		lines = lines->next;
	}
	return (EXIT_SUCCESS);
}