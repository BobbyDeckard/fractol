/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:31:41 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/25 11:31:59 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

void	move_down(t_img *img)
{
	t_fract	*fract;
	double	quarter_range;

	fract = img->fract;
	quarter_range = 0.25 * fract->range;
	ft_printf("\nWorking...\n(moving down)\n");
	if (fract->fract_type == 2)
	{
		fract->y_max -= quarter_range;
		fract->y_min -= quarter_range;
	}
	else
	{
		fract->y_max += quarter_range;
		fract->y_min += quarter_range;
	}
	select_fractal(img);
}

void	move_up(t_img *img)
{
	t_fract	*fract;
	double	quarter_range;

	fract = img->fract;
	quarter_range = 0.25 * fract->range;
	ft_printf("\nWorking...\n(moving up)\n");
	if (fract->fract_type == 2)
	{
		fract->y_max += quarter_range;
		fract->y_min += quarter_range;
	}
	else
	{
		fract->y_max -= quarter_range;
		fract->y_min -= quarter_range;
	}
	select_fractal(img);
}

void	move_left(t_img *img)
{
	t_fract	*fract;
	double	quarter_range;

	fract = img->fract;
	quarter_range = 0.25 * fract->range;
	ft_printf("\nWorking...\n(moving left)\n");
	fract->x_max -= quarter_range;
	fract->x_min -= quarter_range;
	select_fractal(img);
}

void	move_right(t_img *img)
{
	t_fract	*fract;
	double	quarter_range;

	fract = img->fract;
	quarter_range = 0.25 * fract->range;
	ft_printf("\nWorking...\n(moving right)\n");
	fract->x_max += quarter_range;
	fract->x_min += quarter_range;
	select_fractal(img);
}
