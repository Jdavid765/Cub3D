/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:30:00 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/08/10 16:26:18 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Rotate the player's direction vector and camera plane by a small angle.
 * ROT_SPPED was choose by the FPS
 * Uses the standard 2D rotation matrix:
 *   new_x =  x·cos(θ) − y·sin(θ)
 *   new_y =  x·sin(θ) + y·cos(θ)
 */
void	handle_rotation(t_game *game)
{
	double	angle;
	double	prev_dir_x;
	double	prev_plane_x;

	if (!game->keys.rotate_left && !game->keys.rotate_right)
		return ;
	angle = ROT_SPEED;
	if (game->keys.rotate_right)
		angle = -angle;
	/*on applique la rotation au point dir*/
	prev_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = prev_dir_x * sin(angle)
		+ game->player.dir_y * cos(angle);
	/*et l'applique aussi a plane*/
	prev_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = prev_plane_x * sin(angle)
		+ game->player.plane_y * cos(angle);
}

/*
 * Main game loop — called once per frame by MLX.
 *
 *  1. Rotate the player if arrow keys are held.
 *  2. Move the player (forward / backward / strafe) with wall collision.
 *  3. Clear the off-screen buffer to black.
 *  4. Draw the minimap into the buffer.
 *  5. Send the completed buffer to the window in one operation.
 */
int	hook_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	handle_rotation(game);
	handle_movement(game, 0, 0);
	memset(game->frame_buffer, 0,
		game->buffer_pitch * WIN_HEIGHT * sizeof(unsigned int));
	render_minimap(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->frame_image, 0, 0);
	usleep(16000);
	return (0);
}
