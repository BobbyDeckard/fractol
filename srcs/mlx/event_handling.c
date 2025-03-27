/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:27:37 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/25 11:30:38 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

static int	read_keys2(int key_pressed, t_img *img)
{
	if (key_pressed == Z_KEY)
		zoom(img, img->w / 2, img->h / 2);
	else if (key_pressed == U_KEY)
		unzoom(img, img->w / 2, img->h / 2);
	else if (key_pressed == H_KEY)
		print_help();
	return (0);
}

static int	read_keys(int key_pressed, t_img *img)
{
	if (key_pressed == ESC)
		exit_window(img);
	else if (key_pressed == UP)
		move_up(img);
	else if (key_pressed == DOWN)
		move_down(img);
	else if (key_pressed == LEFT)
		move_left(img);
	else if (key_pressed == RIGHT)
		move_right(img);
	else if (key_pressed == I_KEY)
		increase_max_iter(img);
	else if (key_pressed == D_KEY)
		decrease_max_iter(img);
	else if (key_pressed == C_KEY)
		change_palette(img);
	else if (key_pressed == X_KEY)
		rev_palette(img);
	else
		return (read_keys2(key_pressed, img));
	return (0);
}

static int	read_mouse(int button, int x, int y, t_img *img)
{
	static int	repetitions = 0;

	if (button == 4 && repetitions++ % 3 == 0)
		zoom(img, x, y);
	else if (button == 5 && repetitions++ % 3 == 0)
		unzoom(img, x, y);
	if (repetitions == 36)
		repetitions = 0;
	return (0);
}

/*
// Left-click = 1
// Right-click = 2
// Middle-click = 3
// Scroll up = 4
// Scroll down = 5
// rep tries to address several issues with event handling:
// 1st click does not register (allows to click on the window after execution
// without zooming unwillingly)
// only 1 in 10 scrolls are registered, preventing an accumulation of zoom
// actions with a highly sensitive scroll
static int	read_mouse(int button, int x, int y, t_img *img)
{
	static int	rep = 0;

	if ((button == 1 && rep++ != 0) || (button == 4 && rep++ % 10 == 0))
		zoom(img, x, y);
	else if (button == 2 || (button == 5 && rep++ % 10 == 0))
		unzoom(img, x, y);
	return (0);
}
*/
static int	close_window(t_img *img)
{
	exit_window(img);
	return (0);
}

void	hook_events(t_win *win, t_img *img)
{
	mlx_key_hook(win->win_ptr, read_keys, img);
	mlx_mouse_hook(win->win_ptr, read_mouse, img);
	mlx_hook(win->win_ptr, 17, 0, close_window, img);
}
