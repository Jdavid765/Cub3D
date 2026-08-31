/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:46:26 by canoduran         #+#    #+#             */
/*   Updated: 2026/08/13 16:06:35 by pucci17pink      ###   ########.fr       */
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
/*Is searching all char in line for found the position about the player*/

int	check_other_player(t_game *game, char letter, int x, int y)
{
	if (game->player.facing != DIR_NONE)
		return (1);
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	game->floodfil.letter = game->map.grid[y][x];
	if (letter == 'N')
		game->player.facing = DIR_NORTH;
	else if (letter == 'S')
		game->player.facing = DIR_SOUTH;
	else if (letter == 'E')
		game->player.facing = DIR_EAST;
	else if (letter == 'W')
		game->player.facing = DIR_WEST;
	set_player_direction(game);
	return (0);
}
/*Is looking if not other player ar registred and if
have nobody i save the position in x,y*/