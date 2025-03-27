/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:32:08 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/25 11:32:25 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

void	zoom(t_img *img, int x, int y)
{
	t_fract	*fract;
	double	half_range;
	double	scaled_x;
	double	scaled_y;

	fract = img->fract;
	scaled_x = scale_x(img, x);
	scaled_y = scale_y(img, y);
	ft_printf("\nWorking...\n(zooming from %dx to ", (int) fract->zoom);
	fract->zoom *= 2;
	fract->range /= 2;
	half_range = fract->range / 2;
	ft_printf("%dx)\n", (int) fract->zoom);
	fract->x_min = scaled_x - half_range;
	fract->x_max = scaled_x + half_range;
	fract->y_min = scaled_y - half_range;
	fract->y_max = scaled_y + half_range;
	fract->max_iter = 100;
	select_fractal(img);
}

void	unzoom(t_img *img, int x, int y)
{
	t_fract	*fract;
	double	half_range;
	double	scaled_x;
	double	scaled_y;

	fract = img->fract;
	scaled_x = scale_x(img, x);
	scaled_y = scale_y(img, y);
	ft_printf("\nWorking...\n(unzooming from %dx to ", (int) fract->zoom);
	fract->zoom /= 2;
	half_range = fract->range;
	fract->range *= 2;
	ft_printf("%dx)\n", (int) fract->zoom);
	fract->x_min = scaled_x - half_range;
	fract->x_max = scaled_x + half_range;
	fract->y_min = scaled_y - half_range;
	fract->y_max = scaled_y + half_range;
	fract->max_iter = 100;
	select_fractal(img);
}
