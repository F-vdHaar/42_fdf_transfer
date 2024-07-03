/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:19:02 by fvon-der          #+#    #+#             */
/*   Updated: 2024/07/03 12:33:54 by fvon-der         ###   ########.fr       */
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

// Structures
typedef struct s_map
{
	char	**file_content;
	int		width;
	int		height;
	int		**map;
	int		z_max;
	int		z_min;
}	t_map;

typedef struct s_camera
{
	int		zoom;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	float	z_height;
	int		x_offset;
	int		y_offset;
	int		iso;
}	t_camera;

typedef struct s_mouse
{
	int		button;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
}	t_mouse;

typedef struct s_renderer
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_camera	*camera;
	t_mouse		*mouse;
}	t_renderer;

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

// Function Prototypes
// Main
void	initialize(int argc, char *argv[]);
void	cleanup(void);

// Map Utilities
int		**parse_map(const char *filename);
int		validate_map(char **file_content);
void	free_map(int **map, int height);

// Rendering
void	draw_line(t_point start, t_point end, int color);
void	render_map(t_renderer *renderer, t_map *map);
void	put_pixel(t_renderer *renderer, int x, int y, int color);
void	display(t_renderer *renderer);

// Event Handling
int		handle_keypress(int keycode, void *param);
int		handle_mouse(int button, t_point location, void *param);

// Matrix Transformations
void	rotate(t_map *map, float angle);
void	scale(t_map *map, float factor);
void	translate(t_map *map, int dx, int dy);

// Utility Functions
void	fast_mlx_pixel_put(t_renderer *renderer, int x, int y, int color);
void	print_map(int **map);
void	log_error(const char *message);

#endif
