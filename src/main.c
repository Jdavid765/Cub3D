/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:48:29 by canoduran         #+#    #+#             */
/*   Updated: 2026/07/27 13:20:31 by pucci17pink      ###   ########.fr       */
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


/* Hardcoded 5×5 test map — used until the .cub parser is wired in. */
/* Player spawns at the centre looking north.                        */
static void	load_test_map(t_game *game)
{
	static char	*grid[5] = {
		"11111",
		"10001",
		"10S01",
		"10001",
		"11111"
	};

	game->map.grid = grid;
	game->map.width = 5;
	game->map.height = 5;
	game->player.x = 2.5;
	game->player.y = 2.5;
}

/* Temporary entry point — bypasses .cub parsing, boots straight into 3D. */
int	main(void)
{
	t_game	game;
	
	if (ac != 2)
		return (printf("Error bad input\n"), 1);
	init(&game);
	ft_bzero(&game, sizeof(t_game));
	load_test_map(&game);
	game.player.facing = DIR_NORTH;
	set_player_direction(&game);
	if (check_filename(av[1], ".cub", &game))
		return (printf("Is not a .cub\n"), 1);
	if (cub3d(&game))
		return (ft_exit(&game), 1);
	ft_exit(&game);
	if (init_mlx_win(&game))
		return (printf("Error: MLX init failed\n"), 1);
	return (0);
}
