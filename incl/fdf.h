/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:19:02 by fvon-der          #+#    #+#             */
/*   Updated: 2024/06/28 16:46:04 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"

typedef struct s_map_dim
{
	int	width;
	int	height;
}			t_map_dim;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


//--------------------------FDF--------------------------
//--------------------------FDF UTILS-------------------
void			fast_mlx_pixel_put(t_data *data, int x, int y, int color);
//-------------------------MAP UTILS-------------------
int				**parse_map(int fd, t_map_dim *dimensions);
void			free_map(int **map, int height);
//-------------------------TEST UTILS-------------------
void			print_map(int **map);

#endif