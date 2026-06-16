/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:49:27 by canoduran         #+#    #+#             */
/*   Updated: 2026/06/13 12:21:10 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_filename(char *line, char *verif, t_game *game)
{
	char	*check_argument;
	int		i;

	i = 0;
	check_argument = ft_strchr(line, '.');
	if (!check_argument)
		return (1);
	while (check_argument[i] || verif[i])
	{
		if (check_argument[i] != verif[i])
			return (1);
		i++;
	}
	game->filename = line;
	return (0);
}
