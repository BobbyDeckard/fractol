/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:24:43 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/25 11:25:51 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

static int	count_iterations(double x0, double y0, int max_iter)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	int		iterations;

	x = 0;
	y = 0;
	x2 = 0;
	y2 = 0;
	iterations = 0;
	while (x2 + y2 <= 4 && iterations++ < max_iter)
	{
		y = (x + x) * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
	}
	return (iterations);
}

static void	get_escape_time(t_img *img, int Px, int Py, int max_iter)
{
	double	scaled_x;
	double	scaled_y;
	int		color;
	int		iterations;

	scaled_x = scale_x(img, Px);
	scaled_y = scale_y(img, Py);
	iterations = count_iterations(scaled_x, scaled_y, max_iter);
	if (iterations == max_iter)
		color = BLACK;
	else
		color = extract_color(img->fract->palettes, img->fract->palette_id,
				iterations, max_iter);
	put_pixel_img(img, Px, Py, color);
}

t_fract	init_mandelbrot(void)
{
	t_fract	mandelbrot;

	mandelbrot.fract_type = 1;
	mandelbrot.max_iter = 100;
	mandelbrot.zoom = 1;
	mandelbrot.range = 2.5;
	mandelbrot.x_min = -2;
	mandelbrot.x_max = 0.5;
	mandelbrot.y_min = -1.25;
	mandelbrot.y_max = 1.25;
	mandelbrot.palette_id = 0;
	return (mandelbrot);
}

void	mandelbrot(t_img *img)
{
	t_win	*win;
	int		x;
	int		y;

	x = -1;
	while (++x < img->w)
	{
		y = -1;
		while (++y < img->h)
			get_escape_time(img, x, y, img->fract->max_iter);
	}
	win = img->win;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, 0, 0);
	print_status(img);
}
