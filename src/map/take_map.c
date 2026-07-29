/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 12:21:40 by canoduran         #+#    #+#             */
/*   Updated: 2026/07/23 18:37:23 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**read_all_lines(int fd, int total_lines)
{
	char	**raw;
	int		i;

	raw = malloc(sizeof(char *) * (total_lines + 1));
	if (!raw)
		return (NULL);
	i = 0;
	while (i < total_lines)
	{
		raw[i] = get_next_line(fd);
		if (!raw[i])
			return (free_table(raw, i), NULL);
		i++;
	}
	raw[i] = NULL;
	return (raw);
}
/*is for take all the file and put in the table*/

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
/*now when i know where i need to start for take only the maps
i take the pointer i don't need to duplicate and i have only the map*/

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
/*This fonction look all files and parse all the path and when
is finish i return the position when the map start*/

int	open_file(t_game *game)
{
	int		fd;
	int		total_lines;
	char	**raw;
	int		ret;

	fd = open(game->filename, O_RDONLY);
	if (fd < 0)
		return (1);
	total_lines = count_l(fd);
	close(fd);
	if (total_lines <= 0)
		return (1);
	fd = open(game->filename, O_RDONLY);
	if (fd < 0)
		return (1);
	raw = read_all_lines(fd, total_lines);
	close(fd);
	if (!raw)
		return (1);
	ret = split_config_and_map(game, raw, total_lines);
	return (free_table(raw, total_lines), ret);
}
/*That is for count the line in the folder put in table
 split the file texture,color, and map*/

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
