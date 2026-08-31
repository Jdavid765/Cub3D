/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:09:11 by canoduran         #+#    #+#             */
/*   Updated: 2026/08/18 14:41:30 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	pars_int(char **str, int *value)
{
	int	res;
	int	has_digit;

	res = 0;
	has_digit = 0;
	while (**str >= '0' && **str <= '9')
	{
		res = res * 10 + (**str - '0');
		has_digit = 1;
		(*str)++;
		if (res > 255)
			return (0);
	}
	if (!has_digit)
		return (0);
	*value = res;
	return (1);
}
/*This fonction convert string caracteres for the color
and i look if the color is max 255 or min 0*/

int	pars_texture(char **dest, char *path)
{
	int	len;

	if (*dest)
		return (1);
	len = ft_strlen(path);
	while (len > 0 && (path[len - 1] == '\n' || path[len - 1] == ' '))
		len--;
	if (len == 0)
		return (1);
	*dest = ft_substr(path, 0, len);
	if (!*dest)
		return (1);
	return (0);
}
/*her i stock the path about the line and i return with '\n'*/

int	pars_color(t_color *color, int *set_flag, char *str, int i)
{
	int	values[3];

	if (*set_flag)
		return (1);
	while (i < 3)
	{
		while (*str == ' ')
			str++;
		if (!pars_int(&str, &values[i]) || values[i] < 0 || values[i] > 255)
			return (1);
		while (*str == ' ')
			str++;
		if (i < 2 && *str++ != ',')
			return (1);
		i++;
	}
	while (*str == ' ')
		str++;
	if (*str && *str != '\n')
		return (1);
	color->r = values[0];
	color->g = values[1];
	color->b = values[2];
	*set_flag = 1;
	return (0);
}

int	pars_identifier(t_game *game, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (pars_texture(&game->texture.no, line + 3));
	if (!ft_strncmp(line, "SO ", 3))
		return (pars_texture(&game->texture.so, line + 3));
	if (!ft_strncmp(line, "WE ", 3))
		return (pars_texture(&game->texture.we, line + 3));
	if (!ft_strncmp(line, "EA ", 3))
		return (pars_texture(&game->texture.ea, line + 3));
	if (!ft_strncmp(line, "F ", 2))
		return (pars_color(&game->floor_color, &game->floor_set, line + 2, 0));
	return (pars_color(&game->ceiling_color, &game->ceiling_set, line + 2, 0));
}
/*i call the function for look the id is NO, SO, etc..
line+3 is for texture and line+2 is forthe color*/