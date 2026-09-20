/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:30:00 by pucci17pink        #+#    #+#             */
/*   Updated: 2026/09/07 12:30:00 by pucci17pink       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
