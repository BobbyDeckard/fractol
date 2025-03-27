/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:26:00 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/25 11:27:19 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

void	select_fractal(t_img *img)
{
	if (img->fract->fract_type == 1)
		mandelbrot(img);
	else if (img->fract->fract_type == 2)
		julia(img);
	else if (img->fract->fract_type == 3)
		burning_ship(img);
}

double	scale_x(t_img *img, int x)
{
	t_fract	*fract;
	double	x0;

	fract = img->fract;
	x0 = fract->x_min + (double) x * fract->range / (double) img->w;
	return (x0);
}

double	scale_y(t_img *img, int y)
{
	t_fract	*fract;
	double	y0;

	fract = img->fract;
	if (img->fract->fract_type == 2)
		y0 = fract->y_max - (double) y * fract->range / (double) img->h;
	else
		y0 = fract->y_min + (double) y * fract->range / (double) img->h;
	return (y0);
}

void	increase_max_iter(t_img *img)
{
	ft_printf("\nWorking...\n(increasing maximum iterations from %d to ",
		img->fract->max_iter);
	if (img->fract->max_iter == 100)
		img->fract->max_iter = 500;
	else
		img->fract->max_iter += 500;
	ft_printf("%d)\n", img->fract->max_iter);
	select_fractal(img);
}

void	decrease_max_iter(t_img *img)
{
	ft_printf("\nWorking...\n(decreasing maximum iterations from %d to ",
		img->fract->max_iter);
	if (img->fract->max_iter == 500)
		img->fract->max_iter = 100;
	else
		img->fract->max_iter -= 500;
	ft_printf("%d)\n", img->fract->max_iter);
	select_fractal(img);
}
