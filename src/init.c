/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:09:45 by canoduran         #+#    #+#             */
/*   Updated: 2026/09/12 13:45:43 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	ft_bzero(&game->player, sizeof(t_player));
	ft_bzero(&game->map, sizeof(t_map));
	game->player.facing = DIR_NONE;
}
