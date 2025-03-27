/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:20:01 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/25 11:21:29 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

static int	iterate_julia(t_img *img, double x0, double y0, int max_iter)
{
	t_fract	*julia;
	double	x2;
	double	y2;
	int		iterations;

	julia = img->fract;
	x2 = x0 * x0;
	y2 = y0 * y0;
	iterations = 0;
	while (x2 + y2 < (double) julia->radius2 && iterations++ < max_iter)
	{
		y0 = (x0 + x0) * y0 + julia->const_y;
		x0 = x2 - y2 + julia->const_x;
		x2 = x0 * x0;
		y2 = y0 * y0;
	}
	return (iterations);
}

static void	plot_julia(t_img *img, int Px, int Py, int max_iter)
{
	double	scaled_x;
	double	scaled_y;
	int		color;
	int		iterations;

	scaled_x = scale_x(img, Px);
	scaled_y = scale_y(img, Py);
	iterations = iterate_julia(img, scaled_x, scaled_y, max_iter);
	if (iterations == max_iter)
		color = BLACK;
	else
		color = extract_color(img->fract->palettes, img->fract->palette_id,
				iterations, max_iter);
	put_pixel_img(img, Px, Py, color);
}

t_fract	init_julia(char **av)
{
	t_fract	julia;

	julia.fract_type = 2;
	julia.max_iter = 100;
	julia.range = 4;
	julia.zoom = 1;
	julia.x_min = -2;
	julia.x_max = 2;
	julia.y_min = -2;
	julia.y_max = 2;
	julia.const_x = ft_atod(av[2]);
	julia.const_y = ft_atod(av[3]);
	julia.radius = 2;
	julia.radius2 = 4;
	julia.palette_id = 0;
	return (julia);
}

void	julia(t_img *img)
{
	t_win	*win;
	int		x;
	int		y;

	x = -1;
	while (++x < img->w)
	{
		y = -1;
		while (++y < img->h)
			plot_julia(img, x, y, img->fract->max_iter);
	}
	win = img->win;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, 0, 0);
	print_status(img);
}
