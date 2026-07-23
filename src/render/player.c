/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:02:04 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/07/13 16:30:00 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Each helper below sets the player's direction vector (dir_x, dir_y)
 * and camera plane (plane_x, plane_y) for the four cardinal directions.
 *
 * The direction vector is a unit vector pointing where the player looks.
 * The camera plane is perpendicular to the direction; its length controls
 * the field of view (0.66 ≈ 66° horizontal FOV).
 */

void	set_north(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 0.66;
	player->plane_y = 0;
}

void	set_south(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1;
	player->plane_x = -0.66;
	player->plane_y = 0;
}

void	set_east(t_player *player)
{
	player->dir_x = 1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

void	set_west(t_player *player)
{
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -0.66;
}

/* Dispatch to the correct direction helper based on the spawn orientation. */
void	set_player_direction(t_game *game)
{
	if (game->player.facing == DIR_NORTH)
		set_north(&game->player);
	else if (game->player.facing == DIR_SOUTH)
		set_south(&game->player);
	else if (game->player.facing == DIR_EAST)
		set_east(&game->player);
	else if (game->player.facing == DIR_WEST)
		set_west(&game->player);
}
