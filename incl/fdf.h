/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:19:02 by fvon-der          #+#    #+#             */
/*   Updated: 2024/07/08 15:03:18 by fvon-der         ###   ########.fr       */
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

// Keycodes
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_Z_TRANSLATE 6
# define KEY_ZOOM_IN 24
# define KEY_ZOOM_OUT 27
# define KEY_ROTATE_LEFT 0
# define KEY_ROTATE_RIGHT 2
# define KEY_ROTATE_X_UP 13
# define KEY_ROTATE_X_DOWN 1
# define KEY_ROTATE_Z_LEFT 12
# define KEY_ROTATE_Z_RIGHT 14
# define KEY_STRETCH_X 7
# define KEY_STRETCH_Y 16
# define KEY_STRETCH_Z 8

// Mouse button codes
# define MOUSE_LEFT_BUTTON 1
# define MOUSE_RIGHT_BUTTON 2
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

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
	int		is_pressed;
	int		prev_x;
	int		prev_y;
	int		action;
	int		button;
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
	int			win_width;
	int			win_height;
	int			is_focused;
	t_camera	*camera;
	t_mouse		*mouse;
	t_map		*map;
}	t_renderer;

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

// Function Prototypes
void	initialize(int argc, char *argv[], t_renderer **renderer, t_map **map)
void	cleanup(void);

// Map Utilities
int		**parse_map(const char *filename, int *width, int *height);
int		validate_map(char **file_content);
void	free_map(int **map, int height);

// Rendering
void	draw_line(t_point start, t_point end, int color);
void	render_map(t_renderer *renderer, t_map *map);
void	put_pixel(t_renderer *renderer, int x, int y, int color);
void	display(t_renderer *renderer);

// Event Handling
int		handle_keypress(int keycode, t_renderer *renderer);
int		handle_keyrelease(int keycode, t_renderer *renderer);
int		handle_mouse_press(int button, int x, int y, t_renderer *renderer);
int		handle_mouse_release(int button, int x, int y, t_renderer *renderer);
int		handle_mouse_move(int x, int y, t_renderer *renderer);
int		handle_mouse_scroll(int button, int x, int y, t_renderer *renderer);

// Matrix Transformations
void	translate_map(t_map *map, int dx, int dy, int dz);
void	rotate_map(t_map *map, double angle_x, double angle_y, double angle_z);
void	scale_map(t_map *map, double scale_x, double scale_y, double scale_z);
void	zoom_map(t_map *map, double factor);

// Utility Functions
void	fast_mlx_pixel_put(t_renderer *renderer, int x, int y, int color);
void	print_map(int **map);
void	log_error(const char *message);

// Event Hooks Setup
void	setup_event_hooks(t_renderer *renderer);

#endif
