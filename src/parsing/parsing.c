/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:22:57 by canoduran         #+#    #+#             */
/*   Updated: 2026/06/20 21:23:27 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_player(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.grid[y])
	{
		if (all_else_if(game, y))
			return (1);
		y++;
	}
	if (game->player.cardinal == 0)
		return (1);
	if (cpy_the_map(game))
		return (1);
	if (floodfil(game, game->player.x, game->player.y) == 10)
		return (1);
	return (0);
}
