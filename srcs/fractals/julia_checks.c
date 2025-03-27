/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:21:41 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/25 11:21:43 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

static int	check_chars(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '.' && *str != ',' && *str != '-')
			return (1);
		str++;
	}
	return (0);
}

int	check_params(char **av)
{
	if (check_chars(av[2]) || check_chars(av[3]))
		return (1);
	if (ft_atod(av[2]) > 2 || ft_atod(av[2]) < -2)
		return (1);
	if (ft_atod(av[3]) > 2 || ft_atod(av[3]) < -2)
		return (1);
	return (0);
}
