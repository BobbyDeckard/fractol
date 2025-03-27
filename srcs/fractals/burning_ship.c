/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:55:10 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/24 16:55:32 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

// iterations is passed as a parameter only to get around the norminette
// (max 5 variable declarations per function)
static int	bs_iterations(double x0, double y0, int max_iter, int iterations)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	double	xtemp;

	x = x0;
	y = y0;
	x2 = x * x;
	y2 = y * y;
	while (x2 + y2 < 4 && iterations++ < max_iter)
	{
		xtemp = x2 - y2 + x0;
		y = ft_dabs((x + x) * y) + y0;
		x = xtemp;
		x2 = x * x;
		y2 = y * y;
	}
	return (iterations);
}

static void	get_burning_ship(t_img *img, int Px, int Py, int max_iter)
{
	double	scaled_x;
	double	scaled_y;
	int		color;
	int		iterations;

	iterations = 0;
	scaled_x = scale_x(img, Px);
	scaled_y = scale_y(img, Py);
	iterations = bs_iterations(scaled_x, scaled_y, max_iter, iterations);
	if (iterations == max_iter)
		color = BLACK;
	else
		color = extract_color(img->fract->palettes, img->fract->palette_id,
				iterations, max_iter);
	put_pixel_img(img, Px, Py, color);
}

t_fract	init_burning_ship(void)
{
	t_fract	bs;

	bs.fract_type = 3;
	bs.max_iter = 100;
	bs.zoom = 1;
	bs.range = 3;
	bs.x_min = -2;
	bs.x_max = 1;
	bs.y_min = -1.8;
	bs.y_max = 1.2;
	bs.palette_id = 0;
	return (bs);
}

void	burning_ship(t_img *img)
{
	t_win	*win;
	int		x;
	int		y;

	x = -1;
	while (++x < img->w)
	{
		y = -1;
		while (++y < img->h)
			get_burning_ship(img, x, y, img->fract->max_iter);
	}
	win = img->win;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, 0, 0);
	print_status(img);
}
