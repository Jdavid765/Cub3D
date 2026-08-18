/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 18:22:01 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/08/18 14:47:17 by pucci17pink      ###   ########.fr       */
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
	cette fonction sert à bien positionner la minimap par rapport
	au joueur en calculant le décalage entre
	la position du joueur et le centre de l'image
*/
int	get_cam_offset(double player_pos, int board_size)
{
	double	offset;

	offset = (player_pos *(MINIMAP_TILE / 2) - (board_size / 2));
	return ((int)offset);
}

/*
	cette fonction sert à ne pas imprimer les cases qui sont
	au-delà de 3 cases par rapport au joueur
*/
int	is_minimap_range(t_game *game, int col, int row)
{
	if (col < ((int)game->player.x - 3) || col > ((int)game->player.x + 2))
		return (0);
	else if (row < ((int)game->player.y - 3) || row > ((int)game->player.y + 2))
		return (0);
	return (1);
}
