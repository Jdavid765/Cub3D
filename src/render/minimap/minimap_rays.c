/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:30:00 by pucci17pink        #+#    #+#             */
/*   Updated: 2026/09/07 12:30:00 by pucci17pink       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Draw one ray on the minimap, stopping right on the wall it hit.
 * One map cell is (MINIMAP_TILE / 2) pixels wide, the same scale as
 * draw_tile, so perp_dist cells become perp_dist * that in pixels.
 * A short line means a close wall: this is the eye test for the DDA.
 */
void	draw_ray_line(t_game *game, t_ray *ray)
{
	int	center_x;
	int	center_y;
	int	length;
	int	step;

	center_x = (MINIMAP_W / 2);
	center_y = (MINIMAP_H / 2);
	length = (int)(ray->perp_dist * (MINIMAP_TILE / 2));
	if (length > MINIMAP_W)
		length = MINIMAP_W;
	step = 0;
	while (step < length)
	{
		if (center_x + (ray->dir_x * step) < MINIMAP_W
			&& center_y + (ray->dir_y * step) < MINIMAP_H)
		{
			put_pixel(game, center_x + (int)(ray->dir_x * step),
				center_y + (int)(ray->dir_y * step), COLOR_DIR);
		}
		step++;
	}
}

void	single_ray_loop(t_game *game, double dir_x, double dir_y)
{
	t_ray	single_ray;

	cast_ray(game, &single_ray, dir_x, dir_y);
	draw_ray_line(game, &single_ray);
}

/*
 * Send one ray for each slice of the view.
 * cam_x goes from -1 (far left) to +1 (far right) and mixes the look
 * vector with the camera plane, so the rays spread out like a fan.
*/
void	draw_all_rays(t_game *game)
{
	double	cam_x;
	double	ray_x;
	double	ray_y;

	cam_x = -1;
	while (cam_x < 1)
	{
		ray_x = game->player.dir_x + (game->player.plane_x * cam_x);
		ray_y = game->player.dir_y + (game->player.plane_y * cam_x);
		single_ray_loop(game, ray_x, ray_y);
		cam_x += 0.1;
	}
}
