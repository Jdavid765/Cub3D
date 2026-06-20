/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 21:41:41 by canoduran         #+#    #+#             */
/*   Updated: 2026/06/21 00:53:21 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_grid(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->count_line)
	{
		if (game->map.grid)
			free(game->map.grid[i]);
		if (game->map.cpy_grid)
			free(game->map.cpy_grid[i]);
		i++;
	}
	free(game->map.grid);
	free(game->map.cpy_grid);
}

void	free_cpygrid(t_game *game, int position)
{
	int	i;

	i = 0;

	while (i < position)
		free(game->map.cpy_grid[i++]);
	free(game->map.cpy_grid);
}
