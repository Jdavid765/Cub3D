/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:09:45 by canoduran         #+#    #+#             */
/*   Updated: 2026/07/23 17:04:56 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init(t_game *game)
{
	game->filename = NULL;
	game->map.grid = NULL;
	game->map.cpy_grid = NULL;
	game->player.cardinal = none;
	game->count_line = 0;
	game->floodfil.status = 0;
	game->texture.no = NULL;
	game->texture.so = NULL;
	game->texture.we = NULL;
	game->texture.ea = NULL;
	game->floor_set = 0;
	game->ceiling_set = 0;
}
