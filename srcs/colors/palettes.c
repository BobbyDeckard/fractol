/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:04:39 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/25 11:06:54 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

static int	*init_green(int *green)
{
	int	i;
	int	x;

	i = 0;
	x = -1;
	while (++x < 256)
		green[i++] = gen_trgb(0, 0, x, 0);
	while (x-- >= 0)
		green[i++] = gen_trgb(0, 0, x, 0);
	return (green);
}

static int	*init_grey(int *grey)
{
	int	i;
	int	x;

	i = 0;
	x = -1;
	while (++x < 256)
		grey[i++] = gen_trgb(0, x, x, x);
	while (x-- >= 0)
		grey[i++] = gen_trgb(0, x, x, x);
	return (grey);
}

static void	init_wiki(int *wiki)
{
	wiki[0] = gen_trgb(0, 66, 30, 15);
	wiki[1] = gen_trgb(0, 25, 7, 26);
	wiki[2] = gen_trgb(0, 9, 1, 47);
	wiki[3] = gen_trgb(0, 4, 4, 73);
	wiki[4] = gen_trgb(0, 0, 7, 100);
	wiki[5] = gen_trgb(0, 12, 44, 138);
	wiki[6] = gen_trgb(0, 24, 82, 177);
	wiki[7] = gen_trgb(0, 57, 125, 209);
	wiki[8] = gen_trgb(0, 134, 181, 229);
	wiki[9] = gen_trgb(0, 211, 236, 248);
	wiki[10] = gen_trgb(0, 241, 233, 191);
	wiki[11] = gen_trgb(0, 248, 201, 95);
	wiki[12] = gen_trgb(0, 255, 170, 0);
	wiki[13] = gen_trgb(0, 204, 128, 0);
	wiki[14] = gen_trgb(0, 153, 87, 0);
	wiki[15] = gen_trgb(0, 106, 52, 3);
}

static void	init_neon(int *neon)
{
	neon[0] = gen_trgb(0, 25, 25, 112);
	neon[1] = gen_trgb(0, 0, 0, 128);
	neon[2] = gen_trgb(0, 0, 0, 139);
	neon[3] = gen_trgb(0, 75, 0, 130);
	neon[4] = gen_trgb(0, 128, 0, 128);
	neon[5] = gen_trgb(0, 139, 0, 139);
	neon[6] = gen_trgb(0, 199, 21, 133);
	neon[7] = gen_trgb(0, 255, 20, 147);
	neon[8] = gen_trgb(0, 238, 130, 238);
	neon[9] = gen_trgb(0, 221, 160, 221);
	neon[10] = gen_trgb(0, 216, 191, 216);
	neon[11] = WHITE;
	neon[12] = gen_trgb(0, 100, 149, 237);
	neon[13] = gen_trgb(0, 65, 105, 225);
	neon[14] = gen_trgb(0, 72, 61, 139);
	neon[15] = gen_trgb(0, 75, 0, 130);
}

void	init_palettes(int **palettes)
{
	init_wiki(palettes[0]);
	init_neon(palettes[1]);
	init_grey(palettes[2]);
	init_green(palettes[3]);
	init_wacced(palettes[4]);
}
