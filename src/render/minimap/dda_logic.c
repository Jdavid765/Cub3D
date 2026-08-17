/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:13:06 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/08/17 16:53:32 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*
	this fonctions draw all the rays needed for the dda logic
	
*/
void	draw_all_rays(t_game *game)
{
	double	cam_x;
	double	ray_x;
	double	ray_y;
	
	cam_x = -1;
	// draw_direction_line(game, game->player.dir_x, game->player.dir_y);
	while (cam_x < 1)
	{
		ray_x = game->player.dir_x + (game->player.plane_x * cam_x);
		ray_y = game->player.dir_y + (game->player.plane_y * cam_x);
		draw_direction_line(game, ray_x, ray_y);
		
		cam_x += 0.01;
	}
}
