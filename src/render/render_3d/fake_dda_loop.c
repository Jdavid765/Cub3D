/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_dda_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 15:26:01 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/08/31 13:48:45 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	fonction that basically render every ray thrown to the player position
	and do the dda and fill every pixel line right in the image buffer
*/
void	render_dda(t_game *game)
{
	t_ray	ray;
	int	x;
	double	cam_x;
	double	dir_x;
	double	dir_y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		cam_x = 2.0 * x / (double)WIN_WIDTH - 1.0;
		dir_x = game->player.dir_x + game->player.plane_x * cam_x;
		dir_y = game->player.dir_y + game->player.plane_y * cam_x;
		cast_ray(game, &ray, dir_x, dir_y);
		draw_wall(game, &ray, x);
		x++;
	}
}
