/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:30:00 by pucci17pink        #+#    #+#             */
/*   Updated: 2026/09/07 12:30:00 by pucci17pink       ###   ########.fr       */
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
 * Choose the way the ray walks on the x axis (+1 right, -1 left) and
 * measure the first step: the distance from the player to the first
 * vertical grid line on that side. This first step is a partial one,
 * because the player stands in the middle of a cell, not on a line.
 */
void	set_step_x(t_game *game, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.x)
			* ray->delta_dist_x;
	}
}

/* Same idea as set_step_x, but on the y axis (horizontal grid lines). */
void	set_step_y(t_game *game, t_ray *ray)
{
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.y)
			* ray->delta_dist_y;
	}
}
