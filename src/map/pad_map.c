/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 11:22:43 by canoduran         #+#    #+#             */
/*   Updated: 2026/09/17 11:24:18 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	strip_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	pad_map_line(char **line, int width)
{
	char	*new_line;
	int		len;
	int		i;

	len = ft_strlen(*line);
	if (len >= width)
		return (0);
	new_line = malloc(sizeof(char) * (width + 1));
	if (!new_line)
		return (1);
	i = 0;
	while (i < len)
	{
		new_line[i] = (*line)[i];
		i++;
	}
	while (i < width)
		new_line[i++] = ' ';
	new_line[i] = '\0';
	free(*line);
	*line = new_line;
	return (0);
}

int	fill_map_grid(t_game *game, char **raw, int start, int count)
{
	int	i;
	int	len;

	game->map.width = 0;
	i = 0;
	while (i < count)
	{
		game->map.grid[i] = raw[start + i];
		raw[start + i] = NULL;
		strip_newline(game->map.grid[i]);
		len = ft_strlen(game->map.grid[i]);
		if (len > game->map.width)
			game->map.width = len;
		i++;
	}
	game->map.grid[i] = NULL;
	return (0);
}

int	pad_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		if (pad_map_line(&game->map.grid[i], game->map.width))
			return (1);
		i++;
	}
	return (0);
}