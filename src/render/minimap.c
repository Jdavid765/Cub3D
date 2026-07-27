/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:24:28 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/07/23 15:12:06 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Write one pixel into the off-screen frame buffer.
 * Bounds-checked — silently drops pixels outside the window.
 * The buffer is a flat array of 32-bit ARGB colours.
 * buffer_pitch = how many pixels per row (may be > WIN_WIDTH due to GPU
 * memory alignment, so we use it instead of WIN_WIDTH for indexing).
 */
void	put_pixel(t_game *game, int x, int y, unsigned int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		game->frame_buffer[y * game->buffer_pitch + x] = color;
}

/*
 * Fill one grid cell on the minimap with a solid colour.
 * (grid_col, grid_row) is the tile position in the map grid;
 * the pixel position on screen is (col × MINIMAP_TILE, row × MINIMAP_TILE).
 */
void	draw_tile(t_game *game, int grid_col, int grid_row,
		unsigned int color)
{
	int	pixel_x;
	int	pixel_y;
	int	offset_x;
	int	offset_y;

	pixel_x = grid_col * MINIMAP_TILE;
	pixel_y = grid_row * MINIMAP_TILE;
	offset_y = 0;
	while (offset_y < MINIMAP_TILE)
	{
		offset_x = 0;
		while (offset_x < MINIMAP_TILE)
		{
			put_pixel(game, pixel_x + offset_x, pixel_y + offset_y, color);
			offset_x++;
		}
		offset_y++;
	}
}

/* Draw the player as a small red square centred on its map position. */
void	draw_player(t_game *game)
{
	int	center_x;
	int	center_y;
	int	half_size;
	int	offset_x;
	int	offset_y;

	center_x = (int)(game->player.x * MINIMAP_TILE);
	center_y = (int)(game->player.y * MINIMAP_TILE);
	half_size = MINIMAP_TILE / 8;
	offset_y = -half_size;
	while (offset_y < half_size)
	{
		offset_x = -half_size;
		while (offset_x < half_size)
		{
			put_pixel(game, center_x + offset_x,
				center_y + offset_y, COLOR_PLAYER);
			offset_x++;
		}
		offset_y++;
	}
}

/* Draw a short green line from the player showing the look direction. */
void	draw_direction_line(t_game *game)
{
	int		center_x;
	int		center_y;
	double	length;
	int		step;

	center_x = (int)(game->player.x * MINIMAP_TILE);
	center_y = (int)(game->player.y * MINIMAP_TILE);
	length = MINIMAP_TILE / 2;
	step = 0;
	while (step < (int)length)
	{
		put_pixel(game,
			center_x + (int)(game->player.dir_x * step),
			center_y + (int)(game->player.dir_y * step),
			COLOR_DIR);
		step++;
	}
}

/*
 * Draw the complete minimap into the frame buffer.
 * The minimap shows every cell of the map grid (walls = grey, floor =
 * light grey),
 * the player position (red square), and the direction the player is facing
 * (green line).
 * Nothing is sent to the screen here — hook_loop calls
 * mlx_put_image_to_window once per frame after all rendering is done.
 */
void	render_minimap(t_game *game)
{
	int				row;
	int				col;
	unsigned int	color;

	row = 0;
	while (row < game->map.height)
	{
		col = 0;
		while (col < game->map.width)
		{
			if (game->map.grid[row][col] == '1')
				color = COLOR_WALL;
			else
				color = COLOR_FLOOR;
			draw_tile(game, col, row, color);
			col++;
		}
		row++;
	}
	draw_direction_line(game);
	draw_player(game);
}
