/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:30:00 by pucci17pink        #+#    #+#             */
/*   Updated: 2026/09/07 12:30:00 by pucci17pink       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
