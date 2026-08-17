/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:24:28 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/08/17 15:58:39 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include "cub3d.h"

/*
 * Draw the complete minimap into the frame buffer.
 * the player position (red square), and the direction the player is facing
 * (green line).
 * Nothing is sent to the screen here —> hook_loop calls
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
			if (is_minimap_range(game, col, row))
				draw_tile(game, col, row, color);
			col++;
		}
		row++;
	}
	draw_minimap_edge(game);
	draw_player(game);
	draw_all_rays(game);
	draw_plane_line(game);
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

	pixel_x = grid_col * (MINIMAP_TILE / 2) - get_cam_offset(game->player.x, MINIMAP_W);
	pixel_y = grid_row * (MINIMAP_TILE / 2) - get_cam_offset(game->player.y, MINIMAP_H);
	offset_y = 0;
	while (offset_y < (MINIMAP_TILE / 2))
	{
		offset_x = 0;
		while (offset_x < (MINIMAP_TILE / 2))
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
	int	pos_x;
	int	pos_y;

	center_x = MINIMAP_W / 2;
	center_y = MINIMAP_H / 2;
	pos_y = center_y - 5;
	while (pos_y < (center_y + 6))
	{
		pos_x = center_x - 5;
		while (pos_x < (center_x + 6))
		{
			put_pixel(game,pos_x ,pos_y ,COLOR_PLAYER);
			pos_x++;
		}
		pos_y++;
	}
}

/* Draw a short green line from the player showing the look direction. */
void	draw_direction_line(t_game *game, double dir_x, double dir_y)
{
	int		center_x;
	int		center_y;
	double	length;
	int		step;

	center_x = (MINIMAP_W / 2);
	center_y = (MINIMAP_H / 2);
	length = MINIMAP_TILE / 2;
	step = 0;
	while (step < (int)length)
	{
		put_pixel(game,
			center_x + (int)(dir_x * step),
			center_y + (int)(dir_y * step),
			COLOR_DIR);
		step++;
	}
}


void	draw_plane_line(t_game *game)
{
	int		center_x;
	int		center_y;
	double	length;
	int		step;

	center_x = (int)((MINIMAP_TILE / 2) * game->player.dir_x) + (MINIMAP_W / 2);
	center_y = (int)((MINIMAP_TILE / 2) * game->player.dir_y) + (MINIMAP_H / 2);
	length = MINIMAP_TILE / 2;
	step = 0;
	while (step < (int)length)
	{
		put_pixel(game,
			center_x + (int)(game->player.plane_x * step),
			center_y + (int)(game->player.plane_y * step),
			COLOR_PLANE);
		game->player.plane_x *= -1;
		game->player.plane_y *= -1;
		put_pixel(game,
					center_x + (int)(game->player.plane_x * step),
					center_y + (int)(game->player.plane_y * step),
					COLOR_PLANE);
		game->player.plane_x *= -1;
		game->player.plane_y *= -1;
		step++;
	}
}

/*
	ici on dessine le bord de la minimap pas plus complexe que ça ^^
*/
void	draw_minimap_edge(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= MINIMAP_H - 1)
	{
		x = 0;
		while (x <= MINIMAP_W - 1)
		{
			if (y <= 3 || y >= MINIMAP_H - 4)
			{
				put_pixel(game,x ,y ,COLOR_TESTER);
			}
			else if (x <= 3 || x >= MINIMAP_W - 4)
			{
				put_pixel(game,x ,y ,COLOR_TESTER);
			}
			x++;
		}
		y++;
	}
}
