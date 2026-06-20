/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:48:29 by canoduran         #+#    #+#             */
/*   Updated: 2026/06/21 00:47:13 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	cub3d(t_game *game)
{
	if (open_file(game))
		return (printf("Error when open the file\n"), 1);
	if (check_player(game))
		return (printf("Error in the map\n"), 1);
	return (0);
}


int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		init(&game);
		if (check_filename(av[1], ".cub", &game))
			return (printf("Is not a .cub\n"), 1);
		if (cub3d(&game))
			return (ft_exit(&game), 1);
		ft_exit(&game);
	}
	else
		return (printf("Error bad input\n"), 1);
	return (0);
}
