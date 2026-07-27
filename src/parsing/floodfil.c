/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:13:26 by canoduran         #+#    #+#             */
/*   Updated: 2026/07/23 18:20:17 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	floodfil(t_game *game, int x, int y)
{
	if (y < 0 || x < 0 || !game->map.cpy_grid[y]
		|| !game->map.cpy_grid[y][x])
		return (game->floodfil.status = 10, 10);
	if (game->floodfil.status == 10)
		return (10);
	if (game->map.cpy_grid[y][x] == '1' || game->map.cpy_grid[y][x] == 'V')
		return (1);
	else if (game->map.cpy_grid[y][x] == '0'
			|| game->map.cpy_grid[y][x] == game->floodfil.letter)
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
/* 10 = is for tell i found other caracter in the map or not close
1 = is because found a wall or is visited
0 = is for tell all was good (succes)
i look if the player can't exit the map and don't have space
*/

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
			return (free_cpygrid(game, i), 1);
		i++;
	}
	game->map.cpy_grid[i] = NULL;
	return (0);
}
/*i duplicate the original map for doing floodfil
and modified the map i have visited with V*/
