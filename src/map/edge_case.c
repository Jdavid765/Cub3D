/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:09:44 by canoduran         #+#    #+#             */
/*   Updated: 2026/10/07 18:33:48 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_is_valid_cell(t_game *game, int x, int y)
{
	char	*caracter_autorized;

	caracter_autorized = "10 NEWS";
	if (game->map.grid[x][y] == '\n')
		return (0);
	if (ft_strchr(caracter_autorized, game->map.grid[x][y]) == NULL)
		return (1);
	return (0);
}

int	ft_look_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map.grid[x])
	{
		y = 0;
		while(game->map.grid[x][y])
		{
			if (ft_is_valid_cell(game, x , y))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}