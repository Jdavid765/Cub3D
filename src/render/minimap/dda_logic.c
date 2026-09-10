/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:13:06 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/08/31 15:58:24 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Distance the ray travels to cross one full grid cell.
 * A ray_dir close to zero means the ray is almost parallel to that
 * axis, so we return a huge value: this axis is then never the
 * closest one and the walk stays safe.
 */
double	get_delta_dist(double ray_dir)
{
	if (ray_dir > -0.000001 && ray_dir < 0.000001)
		return (1e30);
	return (fabs(1.0 / ray_dir));
}

/*
 * Prepare one ray before the walk starts.
 * The ray leaves the player, so it starts inside the player cell.
 */
void	set_minimap_ray(t_game *game, t_ray *ray, double dir_x, double dir_y)
{
	ray->dir_x = dir_x;
	ray->dir_y = dir_y;
	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;
	ray->delta_dist_x = get_delta_dist(dir_x);
	ray->delta_dist_y = get_delta_dist(dir_y);
	ray->hit = 0;
}

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

/*
 * Full DDA for one ray: setup, first step, walk, then draw it.
 * On exit the ray holds the wall cell, the touched side, both
 * side_dist values and perp_dist, all the 3D render needs.
 */
void	cast_ray(t_game *game, t_ray *ray, double dir_x, double dir_y)
{
	ft_bzero(ray, sizeof(t_ray));
	set_minimap_ray(game, ray, dir_x, dir_y);
	set_step_x(game, ray);
	set_step_y(game, ray);
	dda_walk(game, ray);
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
