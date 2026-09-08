/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:48:29 by canoduran         #+#    #+#             */
/*   Updated: 2026/09/08 13:26:11 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	if (ac != 2)
		return (printf("Error bad input\n"), 1);
	init(&game);
	if (check_filename(av[1], ".cub", &game))
		return (printf("Is not a .cub\n"), 1);
	if (cub3d(&game))
		return (exit_all(&game), 1);
	set_player_direction(&game);
	if (init_mlx_win(&game))
		return (printf("Error: MLX init failed\n"), 1);
	return (0);
}
