/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:13:26 by canoduran         #+#    #+#             */
/*   Updated: 2026/06/20 21:34:33 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3d.h"

int	floodfil(t_game *game, int x, int y)
{
	if (game->floodfil.status == 10)
		return (10);
	if (game->map.cpy_grid[y][x] == '1' || game->map.cpy_grid[y][x] == 'V')
		return (1);
	else if (game->map.cpy_grid[y][x] == '0' || game->map.cpy_grid[y][x] == game->floodfil.letter)
		game->map.cpy_grid[y][x] = 'V';
	else
		return (game->floodfil.status = 10, 10);
	floodfil(game, x, y + 1);
	floodfil(game, x, y - 1);
	floodfil(game, x + 1, y);
	floodfil(game, x - 1, y);
	if (game->floodfil.status == 10)
		return (10);
	return (0);
}
// 10 = pour dire qu'il as rencontrer une lettre differentes dans la map ou map mal fermer
// 1 = car il as rencontrer un mur ou est deja passer par la
// 0 = pour dire que toute la map est bien fermer (succes)
//Erreur ici j ai mal fais un truc je dois check

int	cpy_the_map(t_game *game)
{
	int	i;

	i = 0;
	game->map.cpy_grid = malloc(sizeof(char *) * (game->count_line + 1));
	if (!game->map.cpy_grid)
		return (1);
	while (i < game->count_line)
	{
		game->map.cpy_grid[i] = ft_strdup(game->map.grid[i]);
		if (!game->map.cpy_grid[i])
			return (1);
		i++;
	}
	game->map.cpy_grid[i] = NULL;
	// game->map.cpy_grid[game->player.y][game->player.x] = 'V';
	return (0);
}
