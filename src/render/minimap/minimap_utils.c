/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:30:00 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/09/20 20:56:11 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	cette fonction sert à bien positionner la minimap par rapport
	au joueur en calculant le décalage entre
	la position du joueur et le centre de l'image
*/
int	get_cam_offset(double player_pos, int board_size)
{
	double	offset;

	offset = (player_pos *(MINIMAP_TILE / 2) - (board_size / 2));
	return ((int)offset);
}

/*
	cette fonction sert à ne pas imprimer les cases qui sont
	au-delà de 3 cases par rapport au joueur
*/
int	is_minimap_range(t_game *game, int col, int row)
{
	if (col < ((int)game->player.x - 4) || col > ((int)game->player.x + 3))
		return (0);
	else if (row < ((int)game->player.y - 4) || row > ((int)game->player.y + 3))
		return (0);
	return (1);
}
