/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:48:29 by canoduran         #+#    #+#             */
/*   Updated: 2026/07/07 16:53:13 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int	main(int ac, char **av)
// {
// 	t_game	game;

// 	if (ac != 2)
// 	{
// 		return (printf("Error bad input\n"), 1);
// 	}
// 	init(&game);
// 	if (check_filename(av[1], ".cub", &game))
// 		return (printf("Is not a .cub\n"), 1);
// 	if (open_file(&game))
// 		return (printf("Error when open the file\n"), 1);
// 	if (check_player(&game))
// 		return (printf("Error in the map\n"), 1);
// 	// for (int i = 0; game.map.grid[i]; i++)
// 	// 	printf("%s\n", game.map.grid[i]);

// 	if (init_game(&game))
// 		return (printf("Error init MLX\n"), 1);

// 	return (0);
// }

/* hardcoded test map — 5x5 avec un mur en bordure et un pilier au centre */
void	fill_test_map(t_game *game)
{
	static char	*grid[5] = {
		"11111",
		"10001",
		"10N01",
		"10001",
		"11111"
	};

	game->map.grid = grid;
	game->map.width = 5;
	game->map.height = 5;
}

/* entry point temporaire pour tester le rendu de la minimap */
int	main(void)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	fill_test_map(&game);
	game.player.cardinal = north;
	set_player_dir(&game);
	if (init_game(&game))
		return (printf("Error init MLX\n"), 1);
	return (0);
}
