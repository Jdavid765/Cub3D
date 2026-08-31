/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_walk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 13:45:00 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/08/27 14:20:00 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
