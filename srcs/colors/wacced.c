/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wacced.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:13:25 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/25 11:13:26 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

static void	wacced3(int *wacced, int id)
{
	int	x;

	x = -1;
	while (++x < 256)
		wacced[id++] = gen_trgb(0, 0, 0, x);
	x = -1;
	while (++x < 256)
		wacced[id++] = gen_trgb(0, x, 0, 255);
	x = -1;
	while (++x < 256)
		wacced[id++] = gen_trgb(0, 255, x, 255);
	x = 256;
	while (--x >= 0)
		wacced[id++] = gen_trgb(0, 255, 255, x);
	x = 256;
	while (--x >= 0)
		wacced[id++] = gen_trgb(0, x, 255, 0);
	x = 256;
	while (--x >= 0)
		wacced[id++] = gen_trgb(0, 0, x, 0);
}

static void	wacced2(int *wacced, int id)
{
	int	x;

	x = -1;
	while (++x < 256)
		wacced[id++] = gen_trgb(0, 0, x, 0);
	x = -1;
	while (++x < 256)
		wacced[id++] = gen_trgb(0, 0, 255, x);
	x = -1;
	while (++x < 256)
		wacced[id++] = gen_trgb(0, x, 255, 255);
	x = 256;
	while (--x >= 0)
		wacced[id++] = gen_trgb(0, 255, x, 255);
	x = 256;
	while (--x >= 0)
		wacced[id++] = gen_trgb(0, 255, 0, x);
	x = 256;
	while (--x >= 0)
		wacced[id++] = gen_trgb(0, x, 0, 0);
	return (wacced3(wacced, id));
}

static void	wacced1(int *wacced, int id)
{
	int	x;

	x = -1;
	while (++x < 256)
		wacced[id++] = gen_trgb(0, x, 0, 0);
	x = -1;
	while (++x < 256)
		wacced[id++] = gen_trgb(0, 255, x, 0);
	x = -1;
	while (++x < 256)
		wacced[id++] = gen_trgb(0, 255, 255, x);
	x = 256;
	while (--x >= 0)
		wacced[id++] = gen_trgb(0, x, 255, 255);
	x = 256;
	while (--x >= 0)
		wacced[id++] = gen_trgb(0, 0, x, 255);
	x = 256;
	while (--x >= 0)
		wacced[id++] = gen_trgb(0, 0, 0, x);
	return (wacced2(wacced, id));
}

void	init_wacced(int *wacced)
{
	int	id;

	id = 0;
	return (wacced1(wacced, id));
}
