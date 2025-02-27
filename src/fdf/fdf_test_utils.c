/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:15:59 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/27 18:45:30 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_map(int **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != -1)
		{
			ft_printf("%d ", map[i][j]);
			j++;
		}
		write(1, "\n", sizeof(char));
		i++;
	}
	return (EXIT_SUCCESS);
}

//    ft_printf(file, "%s\n", message);
int	log_error(const char *message)
{
	int	fd;

	fd = open("error.log", O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
	{
		write(2, "Could not open error.log for writing\n", 37);
		return (EXIT_FAILURE);
	}
	ft_printf("%s \n", message);
	write(fd, message, strlen(message));
	write(fd, "\n", 1);
	close(fd);
	return (EXIT_SUCCESS);
}
