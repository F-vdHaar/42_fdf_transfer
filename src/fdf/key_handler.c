/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:29:27 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/23 14:46:24 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> //DEBUG  For printf

static void	handle_translate_key(t_renderer *renderer, int keycode);
static void	handle_scale_key(t_renderer *renderer, int keycode);
static void	handle_rotate_key(t_renderer *renderer, int keycode);
static void	handle_zoom_key(t_renderer *renderer, int keycode);


int handle_keypress(int keycode, t_renderer *renderer)
{
    printf("DEBUG: handle_keypress - Keycode: %d\n", keycode);

    if (keycode == KEY_ESC) {
        printf("DEBUG: handle_keypress - Exiting due to ESC key.\n");
        handle_close(renderer);
    } else if (keycode == KEY_UP || keycode == KEY_DOWN
        || keycode == KEY_LEFT || keycode == KEY_RIGHT
        || keycode == KEY_Z_TRANSLATE) {
        printf("DEBUG: handle_keypress - Calling handle_translate_key.\n");
        handle_translate_key(renderer, keycode);
    } else if (keycode == KEY_ZOOM_IN || keycode == KEY_ZOOM_OUT) {
        printf("DEBUG: handle_keypress - Calling handle_zoom_key.\n");
        handle_zoom_key(renderer, keycode);
    } else if (keycode == KEY_ROTATE_LEFT || keycode == KEY_ROTATE_RIGHT
        || keycode == KEY_ROTATE_X_UP || keycode == KEY_ROTATE_X_DOWN
        || keycode == KEY_ROTATE_Z_LEFT || keycode == KEY_ROTATE_Z_RIGHT) {
        printf("DEBUG: handle_keypress - Calling handle_rotate_key.\n");
        handle_rotate_key(renderer, keycode);
    } else if (keycode == KEY_STRETCH_X || keycode == KEY_STRETCH_Y
        || keycode == KEY_STRETCH_Z) {
        printf("DEBUG: handle_keypress - Calling handle_scale_key.\n");
        handle_scale_key(renderer, keycode);
    }

    printf("DEBUG: handle_keypress - Calling draw_window.\n");
    draw_window(renderer);

    printf("DEBUG: handle_keypress - Returning EXIT_SUCCESS.\n");
    return (EXIT_SUCCESS);
}

static void handle_scale_key(t_renderer *renderer, int keycode)
{
    printf("DEBUG: handle_scale_key - Keycode: %d\n", keycode);

    if (keycode == KEY_STRETCH_X) {
        printf("DEBUG: handle_scale_key - Calling handle_scale with x_scale 1.1.\n");
        handle_scale(renderer, 1.1, 1.0, 1.0);
    } else if (keycode == KEY_STRETCH_Y) {
        printf("DEBUG: handle_scale_key - Calling handle_scale with y_scale 1.1.\n");
        handle_scale(renderer, 1.0, 1.1, 1.0);
    } else if (keycode == KEY_STRETCH_Z) {
        printf("DEBUG: handle_scale_key - Calling handle_scale with z_scale 1.1.\n");
        handle_scale(renderer, 1.0, 1.0, 1.1);
    }
}

static void handle_rotate_key(t_renderer *renderer, int keycode)
{
    printf("DEBUG: handle_rotate_key - Keycode: %d\n", keycode);

    if (keycode == KEY_ROTATE_LEFT) {
        printf("DEBUG: handle_rotate_key - Calling handle_rotate with y_angle 0.1.\n");
        handle_rotate(renderer, 0, 0.1, 0);
    } else if (keycode == KEY_ROTATE_RIGHT) {
        printf("DEBUG: handle_rotate_key - Calling handle_rotate with y_angle -0.1.\n");
        handle_rotate(renderer, 0, -0.1, 0);
    } else if (keycode == KEY_ROTATE_X_UP) {
        printf("DEBUG: handle_rotate_key - Calling handle_rotate with x_angle 0.1.\n");
        handle_rotate(renderer, 0.1, 0, 0);
    } else if (keycode == KEY_ROTATE_X_DOWN) {
        printf("DEBUG: handle_rotate_key - Calling handle_rotate with x_angle -0.1.\n");
        handle_rotate(renderer, -0.1, 0, 0);
    } else if (keycode == KEY_ROTATE_Z_LEFT) {
        printf("DEBUG: handle_rotate_key - Calling handle_rotate with z_angle 0.1.\n");
        handle_rotate(renderer, 0, 0, 0.1);
    } else if (keycode == KEY_ROTATE_Z_RIGHT) {
        printf("DEBUG: handle_rotate_key - Calling handle_rotate with z_angle -0.1.\n");
        handle_rotate(renderer, 0, 0, -0.1);
    }
}

static void handle_zoom_key(t_renderer *renderer, int keycode)
{
    printf("DEBUG: handle_zoom_key - Keycode: %d\n", keycode);

    if (keycode == KEY_ZOOM_IN) {
        printf("DEBUG: handle_zoom_key - Calling handle_zoom with factor 1.1.\n");
        handle_zoom(renderer, 1.1);
    } else if (keycode == KEY_ZOOM_OUT) {
        printf("DEBUG: handle_zoom_key - Calling handle_zoom with factor 0.9.\n");
        handle_zoom(renderer, 0.9);
    }
}

static void handle_translate_key(t_renderer *renderer, int keycode) {
    printf("DEBUG: handle_translate_key - Keycode: %d\n", keycode);

    if (keycode == KEY_UP) {
        printf("DEBUG: handle_translate_key - Calling handle_translate with dy -10.\n");
        handle_translate(renderer, 0, -10, 0);
    } else if (keycode == KEY_DOWN) {
        printf("DEBUG: handle_translate_key - Calling handle_translate with dy 10.\n");
        handle_translate(renderer, 0, 10, 0);
    } else if (keycode == KEY_LEFT) {
        printf("DEBUG: handle_translate_key - Calling handle_translate with dx -10.\n");
        handle_translate(renderer, -10, 0, 0);
    } else if (keycode == KEY_RIGHT) {
        printf("DEBUG: handle_translate_key - Calling handle_translate with dx 10.\n");
        handle_translate(renderer, 10, 0, 0);
    } else if (keycode == KEY_Z_TRANSLATE) {
        printf("DEBUG: handle_translate_key - Calling handle_translate with dz 10.\n");
        handle_translate(renderer, 0, 0, 10);
    }
}