/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:07:20 by canoduran         #+#    #+#             */
/*   Updated: 2026/07/23 17:08:42 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	is_config_line(char *line)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
		return (1);
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

int	free_table(char **raw, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (raw[i])
			free(raw[i]);
		i++;
	}
	free(raw);
	return (1);
}

int	all_configuration_found(t_game *game)
{
	if (!game->texture.no || !game->texture.so
		|| !game->texture.we || !game->texture.ea)
		return (0);
	if (!game->floor_set || !game->ceiling_set)
		return (0);
	return (1);
}
