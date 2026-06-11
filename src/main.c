/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:48:29 by canoduran         #+#    #+#             */
/*   Updated: 2026/06/11 15:31:26 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (check_filename(av[1], ".cub"))
			return(printf("Is not a .cub\n"), 1);
	}
	else
		return (printf("Error bad input\n"), 1);
	return (0);
}
