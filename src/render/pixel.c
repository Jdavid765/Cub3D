/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:30:00 by pucci17pink        #+#    #+#             */
/*   Updated: 2026/09/07 12:30:00 by pucci17pink       ###   ########.fr       */
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
