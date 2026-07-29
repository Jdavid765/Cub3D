/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:43 by david             #+#    #+#             */
/*   Updated: 2025/11/05 00:55:22 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strcpy(char *line, int *position)
{
	char	*dest;
	int		total;
	char	*start;

	total = ft_strlen(line) + 1;
	start = malloc((total + 1) * sizeof(char));
	dest = start;
	while (line[*position] && line[*position] != '\n')
	{
		*dest++ = line[*position];
		(*position)++;
	}
	if (line[*position] == '\n')
	{
		*dest++ = line[*position];
		(*position)++;
	}
	*dest = '\0';
	return (start);
}

int	gnl_strchr(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == '\n')
			return (1);
		x++;
	}
	return (0);
}

char	*gnl_strdup(char *s, int position)
{
	char	*cpy;
	int		size;
	int		i;

	size = ft_strlen(s) + 1;
	i = 0;
	cpy = malloc(size * sizeof(char));
	if (!cpy)
		return (NULL);
	while (s[position])
	{
		cpy[i] = s[position];
		i++;
		position++;
	}
	cpy[i] = '\0';
	return (cpy);
}
