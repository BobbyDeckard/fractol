/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:57:20 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/25 11:03:06 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

/* ILLEGAL
#include <stdio.h>
void	print_status(t_img *img)
{
	t_fract	*fractal;

	fractal = img->fract;
	ft_printf("\nDone:_____________________________________________\n");
	// replace next printf with ft_printf
	printf("Scale:\t\t\tx: %f\t%f\n\t\t\ty: %f\t%f\n", fractal->x_min,
		fractal->x_max, fractal->y_min, fractal->y_max);
	ft_printf("Zoom level:\t\t%ux\n", fractal->zoom);
	ft_printf("Maximum iterations:\t%d\n", fractal->max_iter);
	if (fractal->fract_type == 2)
		printf("Escape radius:\t%f\n", fractal->radius);
	ft_printf("_________________Press H to see available commands\n");
}
*/

void	print_status(t_img *img)
{
	t_fract	*fractal;

	fractal = img->fract;
	ft_printf("\nDone:_____________________________________________\n");
	ft_printf("Zoom level:\t\t%ux\n", fractal->zoom);
	ft_printf("Maximum iterations:\t%d\n", fractal->max_iter);
	ft_printf("_________________Press H to see available commands\n");
}

void	print_help(void)
{
	ft_printf("The following commands are at your disposal:\n");
	ft_printf("\n[Keys]\n");
	ft_printf("ESC\texit program\n");
	ft_printf("I\t[I]ncrease maximum iterations\n");
	ft_printf("D\t[D]ecrease maximum iterations\n");
	ft_printf("C\t[C]hange color palette\n");
	ft_printf("Z\tzoom in ([Z]oom)\nU\tzoom out ([U]nzoom)\n");
	ft_printf("\n[Arrows]\n");
	ft_printf("UP\tmove up\nDOWN\tmove down\n");
	ft_printf("LEFT\tmove left\nRIGHT\tmove right\n");
	ft_printf("\n[Mouse]\n");
	ft_printf("Scroll up or left-click to zoom in\n");
	ft_printf("Scroll down or right-click to zoom out\n");
}

void	print_options(void)
{
	ft_printf("Please enter the name of the fractal you would like to explore");
	ft_printf(" as a command line argument.\n\n");
	ft_printf("Available options are:\nMandelbrot\n");
	ft_printf("Julia <c_real> <c_imaginary>\n\n");
	ft_printf("\tWhere <c_real> and <c_imaginary> are the two parts of");
	ft_printf(" the complex number c.\n");
	ft_printf("\tThose values are decimal numbers limited by -2.0 and 2.0");
	ft_printf(" (included).\n\n");
	ft_printf("\tNotable Julia sets:\n");
	ft_printf("\t\t-0.381967\t 0.618033\n");
	ft_printf("\t\t 0.285\t\t 0\n");
	ft_printf("\t\t 0.285\t\t 0.01\n");
	ft_printf("\t\t 0.45\t\t 0.1428\n");
	ft_printf("\t\t-0.70176\t-0.3842\n");
	ft_printf("\t\t-0.835\t\t-0.2321\n");
	ft_printf("\t\t-0.8\t\t 0.156\n");
	ft_printf("\t\t-0.7269\t\t 0.1889\n");
	ft_printf("\t\t 0\t\t 0.8\n");
	ft_printf("\t\t 0.35\t\t 0.35\n");
	ft_printf("\t\t 0.4\t\t 0.4\n");
}
