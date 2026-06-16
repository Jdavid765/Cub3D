/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 12:21:40 by canoduran         #+#    #+#             */
/*   Updated: 2026/06/16 18:22:13 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	open_file(t_game *game)
{
	int	fd;
	int	count_lines;

	count_lines = 0;
	fd = open(game->filename, O_RDONLY);
	if (fd < 0)
		return (1);
	count_lines = count_l(fd);
	close(fd);
	if (count_lines <= 0)
		return (1);
	fd = open(game->filename, O_RDONLY);
	if (fd < 0)
		return (1);
	if (add_map_in_grid(game, count_lines, fd))
		return (close(fd), 1);
	close(fd);
	return (0);
}

int	add_map_in_grid(t_game *game, int count_lines, int fd)
{
	int	position;

	position = 0;
	game->map.grid = malloc((count_lines + 1) * sizeof(char *));
	if (!game->map.grid)
		return (1);
	while (position < count_lines)
	{
		game->map.grid[position] = get_next_line(fd);
		if (!game->map.grid[position])
			return (1);
		position++;
	}
	game->count_line = count_lines;
	game->map.grid[position] = NULL;
	return (0);
}

int	count_l(int fd)
{
	char	*value;
	int		count;

	value = NULL;
	count = 0;
	while (1)
	{
		value = get_next_line(fd);
		if (!value)
			break ;
		count++;
		free(value);
	}
	return (count);
}
/*I can count line for my table how many table i need to malloc*/