/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:24:28 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/07/07 18:25:00 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  draw a filled TILE_SIZE x TILE_SIZE square at minimap position */
void	draw_tile(t_game *game, int map_x, int map_y, uint32_t color)
{
	int	x;
	int	y;
	int	pixel_x;
	int	pixel_y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			pixel_x = map_x * TILE_SIZE + x;
			pixel_y = map_y * TILE_SIZE + y;
			mlx_pixel_put(game->mlx, game->win, pixel_x, pixel_y, color);
			x++;
		}
		y++;
	}
}

/*  draw the 2D minimap grid in the top-left corner of the window */
void	render_minimap(t_game *game)
{
	int	map_x;
	int	map_y;

	map_y = 0;
	while (map_y < game->map.height)
	{
		map_x = 0;
		while (map_x < game->map.width)
		{
			if (game->map.grid[map_y][map_x] == '1')
				draw_tile(game, map_x, map_y, C_WALL);
			map_x++;
		}
		map_y++;
	}
}
