/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 15:00:00 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/07/23 14:49:15 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Return 1 if the given map coordinates are inside a wall, 0 otherwise.  */
/* Out-of-bounds positions are treated as walls*/
int	is_wall(t_game *game, double x, double y)
{
	int	tile_x;
	int	tile_y;

	tile_x = (int)x;
	tile_y = (int)y;
	if (tile_x < 0 || tile_x >= game->map.width
		|| tile_y < 0 || tile_y >= game->map.height)
		return (1);
	return (game->map.grid[tile_y][tile_x] == '1');
}

/*
 * Attempt to move the player by (move_x, move_y), with wall-sliding.
 * If the full diagonal move is blocked, try each axis alone.
 */
void	slide_move(t_game *game, double move_x, double move_y)
{
	if (!is_wall(game, game->player.x + move_x, game->player.y + move_y))
	{
		game->player.x += move_x;
		game->player.y += move_y;
		return ;
	}
	if (!is_wall(game, game->player.x + move_x, game->player.y))
		game->player.x += move_x;
	if (!is_wall(game, game->player.x, game->player.y + move_y))
		game->player.y += move_y;
}

/*
 * Build a movement vector from the currently held keys, then apply it.
 *(x,y)
 *   W / forward    → move in the direction the player is looking (+,+)
 *   S / backward   → move opposite to the look direction(-,-)
 *   A / move_left  → move perpendicular-left
 *   D / move_right → move perpendicular-right
 */
void	handle_movement(t_game *game, double move_x, double move_y)
{
	if (game->keys.forward)
	{
		move_x += game->player.dir_x * MOVE_SPEED;
		move_y += game->player.dir_y * MOVE_SPEED;
	}
	if (game->keys.backward)
	{
		move_x -= game->player.dir_x * MOVE_SPEED;
		move_y -= game->player.dir_y * MOVE_SPEED;
	}
	if (game->keys.move_left)
	{
		move_x -= game->player.dir_y * MOVE_SPEED;
		move_y += game->player.dir_x * MOVE_SPEED;
	}
	if (game->keys.move_right)
	{
		move_x += game->player.dir_y * MOVE_SPEED;
		move_y -= game->player.dir_x * MOVE_SPEED;
	}
	slide_move(game, move_x, move_y);
}

/*
 * X11 KeyPress handler (event mask 1L << 0).
 * Sets the corresponding key flag to true.
 * ESC kills the window and exits immediately.
 */
int	key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
		exit(0);/*à améliorer*/
	}
	if (keycode == KEY_W)
		game->keys.forward = true;
	if (keycode == KEY_A)
		game->keys.move_left = true;
	if (keycode == KEY_S)
		game->keys.backward = true;
	if (keycode == KEY_D)
		game->keys.move_right = true;
	if (keycode == KEY_LEFT)
		game->keys.rotate_left = true;
	if (keycode == KEY_RIGHT)
		game->keys.rotate_right = true;
	return (0);
}

/*
 * X11 KeyRelease handler (event mask 1L << 1).
 * Clears the corresponding key flag.
 */
int	key_release(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_W)
		game->keys.forward = false;
	if (keycode == KEY_A)
		game->keys.move_left = false;
	if (keycode == KEY_S)
		game->keys.backward = false;
	if (keycode == KEY_D)
		game->keys.move_right = false;
	if (keycode == KEY_LEFT)
		game->keys.rotate_left = false;
	if (keycode == KEY_RIGHT)
		game->keys.rotate_right = false;
	return (0);
}
