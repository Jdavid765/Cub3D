/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:30:00 by pucci17pink        #+#    #+#             */
/*   Updated: 2026/09/07 12:30:00 by pucci17pink       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	build_map(t_game *game, char **raw, int start, int total)
{
	int	count;
	int	len;
	int	i;

	count = total - start;
	if (count <= 0)
		return (1);
	game->map.grid = malloc(sizeof(char *) * (count + 1));
	if (!game->map.grid)
		return (1);
	game->map.width = 0;
	i = 0;
	while (i < count)
	{
		game->map.grid[i] = raw[start + i];
		raw[start + i] = NULL;
		len = ft_strlen(game->map.grid[i]);
		if (len > game->map.width)
			game->map.width = len;
		i++;
	}
	game->map.grid[i] = NULL;
	game->map.height = count;
	game->count_line = count;
	return (0);
}

int	split_config_and_map(t_game *game, char **raw, int total_lines)
{
	int	i;
	int	map_start;

	i = 0;
	map_start = -1;
	while (i < total_lines && map_start == -1)
	{
		if (is_empty_line(raw[i]))
			i++;
		else if (is_config_line(raw[i]))
		{
			if (pars_identifier(game, raw[i]))
				return (1);
			i++;
		}
		else
			map_start = i;
	}
	if (map_start == -1 || !all_configuration_found(game))
		return (1);
	return (build_map(game, raw, map_start, total_lines));
}
