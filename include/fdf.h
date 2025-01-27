/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:10:04 by fvon-der          #+#    #+#             */
/*   Updated: 2025/01/26 17:01:56 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
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

typedef enum e_keymode
{
	ROTATE_MODE,
	TRANSLATE_MODE,
	SCALE_MODE,
	NO_MODE
}	t_keymode;

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
	t_keymode	keymode;
}	t_renderer;

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;


// Function Prototypes
void	initialize(int argc, char *argv[], t_renderer **renderer, t_map **map);
void	cleanup(t_renderer *renderer, t_map *map);

// Map
void	init_map(t_map **map, const char *filename);
int		**parse_map(const char *filename);
int		validate_map(char **file_content);
void	free_map(int **map, int height);
// Map Utilities
int		count_words(const char *str, char delimiter);
int		**allocate_map(int height);

// Camera
void	init_camera(t_renderer *renderer);

// Line
void	draw_vertical_lines(t_renderer *renderer, t_map *map, int x, int y);
void	draw_horizontal_lines(t_renderer *renderer, t_map *map, int x, int y);
void	draw_line(t_renderer *renderer, t_point start, t_point end, int color);
//-- Rendering
void	render_map(t_renderer *renderer, t_map *map);
void	put_pixel(t_renderer *renderer, int x, int y, int color);
void	display(t_renderer *renderer);

// Draw
void	bresenham_draw(t_renderer *renderer,
			t_point start, t_point end, int color);
void	init_line_params(t_point start, t_point end,
			t_point *delta, t_point *sign);

// Event Handling
int		handle_keypress(int keycode, t_renderer *renderer);
int		handle_keyrelease(int keycode, t_renderer *renderer);

// Mouse Handler
void	init_mouse(t_renderer *renderer);
void	handle_mouse_zoom(t_renderer *renderer, int button);
int		handle_mouse_press(int button, int x, int y, t_renderer *renderer);
int		handle_mouse_release(t_renderer *renderer);
int		handle_mouse_move(int x, int y, t_renderer *renderer);

// Matrix Transformations
void	handle_translate(t_renderer *renderer, double dx, double dy);
void	handle_rotate(t_renderer *renderer, double x_angle, double y_angle, double z_angle);
void	handle_scale(t_renderer *renderer, double x_scale, double y_scale, double z_scale);
void	handle_zoom(t_renderer *renderer, double factor);

// Utility Functions
void	fast_mlx_pixel_put(t_renderer *renderer, int x, int y, int color);
void	print_map(int **map);
void	log_error(const char *message);

// Event Hooks Setup
void	setup_event_hooks(t_renderer *renderer);

#endif