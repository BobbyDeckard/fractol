/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:12:02 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/25 11:13:09 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

static void	print_color_palette(int id)
{
	if (id == 0)
		ft_printf("Wikipedia Blue-Orange)\n");
	else if (id == 1)
		ft_printf("Custom Neon-ish Blue-Pink)\n");
	else if (id == 2)
		ft_printf("(Literally) 256 Shades of Grey)\n");
	else if (id == 3)
		ft_printf("Matrix Green)\n");
	else if (id == 4)
		ft_printf("Wacced Out Idea)\n");
	else
		ft_printf("Pure Black and White)\n");
}

void	rev_palette(t_img *img)
{
	int	id;

	id = img->fract->palette_id;
	if (id > 0)
		(img->fract->palette_id)--;
	else
		img->fract->palette_id = 5;
	ft_printf("Working...\n(changing color palette to ");
	print_color_palette(img->fract->palette_id);
	select_fractal(img);
}

void	change_palette(t_img *img)
{
	int	id;

	id = img->fract->palette_id;
	if (id < 5)
		(img->fract->palette_id)++;
	else
		img->fract->palette_id = 0;
	ft_printf("Working...\n(changing color palette to ");
	print_color_palette(img->fract->palette_id);
	select_fractal(img);
}

int	extract_color(int **palettes, int id, int iterations, int max_iter)
{
	if (iterations < max_iter && iterations > 0 && id < 2)
		return (palettes[id][iterations % 16]);
	else if (iterations < max_iter && iterations > 0 && id < 4)
		return (palettes[id][iterations % 256]);
	else if (iterations < max_iter && iterations > 0 && id == 4)
		return (palettes[id][iterations % 4608]);
	else if (iterations < max_iter && iterations > 0 && iterations % 2 == 1)
		return (WHITE);
	else
		return (BLACK);
}
