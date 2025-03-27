/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:35 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/22 15:14:40 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

static void	init_mlx(t_win *win, t_img *img)
{
	*win = new_window(RESOLUTION, RESOLUTION, "Ivo's fractol");
	*img = new_image(win, RESOLUTION, RESOLUTION);
	hook_events(win, img);
}

static void	run_fractol(t_fract *fract, t_win *win, t_img *img, int **palettes)
{
	int		wiki[16];
	int		neon[16];
	int		grey[512];
	int		green[512];
	int		wacced[4608];

	init_mlx(win, img);
	palettes[0] = wiki;
	palettes[1] = neon;
	palettes[2] = grey;
	palettes[3] = green;
	palettes[4] = wacced;
	init_palettes(palettes);
	fract->palettes = palettes;
	img->fract = fract;
	select_fractal(img);
	mlx_loop(img->win->mlx_ptr);
	destroy_all(img);
}

int	main(int ac, char **av)
{
	t_fract	fract;
	t_win	win;
	t_img	img;
	int		*palettes[5];

	if (ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10))
		fract = init_mandelbrot();
	else if (ac == 3 && !ft_strncmp(av[1], "Burning", 7)
		&& !ft_strncmp(av[2], "Ship", 4))
		fract = init_burning_ship();
	else if (ac == 4 && !ft_strncmp(av[1], "Julia", 5) && !check_params(av))
		fract = init_julia(av);
	else
	{
		print_options();
		return (0);
	}
	run_fractol(&fract, &win, &img, palettes);
	return (0);
}
