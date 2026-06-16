/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:46:26 by canoduran         #+#    #+#             */
/*   Updated: 2026/06/15 16:55:38 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	all_else_if(t_game *game, int y)
{
	int	x;

	x = 0;
	while (game->map.grid[y][x])
	{
		if (game->map.grid[y][x] == 'N' && check_other_player(game, 'N', x, y))
			return (1);
		else if (game->map.grid[y][x] == 'S'
					&& check_other_player(game, 'S', x, y))
			return (1);
		else if (game->map.grid[y][x] == 'E'
					&& check_other_player(game, 'E', x, y))
			return (1);
		else if (game->map.grid[y][x] == 'W'
					&& check_other_player(game, 'W', x, y))
			return (1);
		x++;
	}
	return (0);
}

int	check_other_player(t_game *game, char letter, int x, int y)
{
	if (game->player.cardinal != 0)
		return (1);
	game->player.x = x;
	game->player.y = y;
	if (letter == 'N')
		game->player.cardinal = north;
	else if (letter == 'S')
		game->player.cardinal = south;
	else if (letter == 'E')
		game->player.cardinal = east;
	else if (letter == 'W')
		game->player.cardinal = west;
	return (0);
}
