/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:48:29 by canoduran         #+#    #+#             */
/*   Updated: 2026/06/10 10:13:39 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	if (ac > 2 || ac <= 1)
		return (1);
	else
	{
		if (ft_comp(av[1], ".cub"))
			return (printf("Error in the Filename\n"), 1);
	}
	return (0);
}
