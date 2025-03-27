/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:30:52 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/25 11:31:25 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

t_win	new_window(int height, int width, char *str)
{
	t_win	win;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		exit(1);
	win_ptr = mlx_new_window(mlx_ptr, width, height, str);
	if (!win_ptr)
		exit(1);
	win.mlx_ptr = mlx_ptr;
	win.win_ptr = win_ptr;
	win.height = height;
	win.width = width;
	return (win);
}

t_img	new_image(t_win *win, int height, int width)
{
	t_img	img;

	img.win = win;
	img.h = height;
	img.w = width;
	img.img_ptr = mlx_new_image(win->mlx_ptr, width, height);
	img.addr = mlx_get_data_addr(img.img_ptr, &(img.bpp), &(img.line_len),
			&(img.endian));
	return (img);
}

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img->w && y < img->h)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *) dst = color;
	}
}

void	destroy_all(t_img *img)
{
	mlx_destroy_image(img->win->mlx_ptr, img->img_ptr);
	mlx_destroy_window(img->win->mlx_ptr, img->win->win_ptr);
	mlx_destroy_display(img->win->mlx_ptr);
	free(img->win->mlx_ptr);
}

void	exit_window(t_img *img)
{
	destroy_all(img);
	exit (0);
}
