/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:48:29 by canoduran         #+#    #+#             */
/*   Updated: 2026/06/15 16:57:22 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		init(&game);
		if (check_filename(av[1], ".cub", &game))
			return (printf("Is not a .cub\n"), 1);
		if (open_file(&game))
			return (printf("Error when open the file\n"), 1);
		if (check_player(&game))
			return (printf("Error in the map\n"), 1);
		for (int i = 0; game.map.grid[i]; i++)
			printf("%s\n", game.map.grid[i]);
	}
	else
		return (printf("Error bad input\n"), 1);
	return (0);
}
