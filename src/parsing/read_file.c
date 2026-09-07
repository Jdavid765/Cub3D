/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:30:00 by pucci17pink        #+#    #+#             */
/*   Updated: 2026/09/07 12:30:00 by pucci17pink       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
