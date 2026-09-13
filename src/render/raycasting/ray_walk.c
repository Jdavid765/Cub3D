/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_walk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:30:00 by pucci17pink        #+#    #+#             */
/*   Updated: 2026/09/07 12:30:00 by pucci17pink       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Walk the ray from grid line to grid line until it lands on a wall.
 * We always jump to the closest line: if the next vertical line is
 * nearer we move on x and side is 0, else we move on y and side is 1.
 * is_wall also answers 1 outside the map, so the loop always ends.
 */
void	dda_walk(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (is_wall(game, ray->map_x, ray->map_y))
			ray->hit = 1;
	}
	set_perp_dist(ray);
}

/*
 * Distance from the player to the wall, measured square to the camera
 * plane. When the walk stops, side_dist holds one step too many: it
 * already aims at the next grid line, so we step back one delta_dist.
 * Using this distance instead of the straight one kills the fisheye.
 */
void	set_perp_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_dist = ray->side_dist_y - ray->delta_dist_y;
	if (ray->perp_dist < 0.0001)
		ray->perp_dist = 0.0001;
}
