/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:16:12 by canoduran         #+#    #+#             */
/*   Updated: 2026/08/26 19:31:41 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	correction_fisheye(t_ray *ray, int *draw_start, int *draw_end)
{
	int	line_height;

	/* Fisheye correction by calculating the perpendicular distance */
	if (ray->side == 0)
		ray->perp_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_dist = (ray->side_dist_y - ray->delta_dist_y);
	if (ray->perp_dist <= 0.0001)
		ray->perp_dist = 0.0001;
	/* Calculation of wall height and boundaries */
	line_height = (int)(WIN_HEIGHT / ray->perp_dist);
	*draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (*draw_end >= WIN_HEIGHT)
		*draw_end = WIN_HEIGHT - 1;
}

void	fill_wall(t_game *game, t_ray *ray, int x,
		int draw_start, int draw_end)
{
	int	y;

	y = 0;
	while (y < WIN_HEIGHT) /* Iterate through the column from top to bottom */
	{
		if (y < draw_start)
			put_pixel(game, x, y, 0xFF87CEEB);
		else if (y >= draw_start && y <= draw_end)
		{
			if (ray->side == 1)
				put_pixel(game, x, y, COLOR_WALL - 0x00222222); /* Darken the walls with artificial light. */
			else
				put_pixel(game, x, y, COLOR_WALL);
		}
		else
			put_pixel(game, x, y, COLOR_FLOOR); /* Ground */
		y++;
	}
}

/* Function to be called once the ray has hit a wall (hit == 1) */
void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int	draw_start;
	int	draw_end;

	correction_fisheye(ray, &draw_start, &draw_end);
	fill_wall(game, ray, x, draw_start, draw_end);
}