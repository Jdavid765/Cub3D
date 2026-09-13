/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:16:12 by canoduran         #+#    #+#             */
/*   Updated: 2026/08/31 16:02:22 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	correction_fisheye(t_ray *ray, int *draw_start, int *draw_end)
{
	int	line_height;

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

/*
 Function to be called once the ray has hit a wall (hit == 1) 
*/
void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int	draw_start;
	int	draw_end;

	correction_fisheye(ray, &draw_start, &draw_end);
	fill_wall(game, ray, x, draw_start, draw_end);
}
