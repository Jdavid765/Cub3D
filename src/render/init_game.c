/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:27:29 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/08/18 14:46:08 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Create the off-screen frame image and retrieve its pixel buffer.
 * One frame = one big array of pixels we draw into before
 	blitting to the window.
 */
int	create_frame_buffer(t_game *game)
{
	char	*pixel_data;
	int		bits_per_pixel;
	int		bytes_per_line;
	int		endian;

	game->frame_image = mlx_new_image(game->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!game->frame_image)
		return (printf("Error: mlx_new_image\n"), 1);
	pixel_data = mlx_get_data_addr(game->frame_image,
			&bits_per_pixel, &bytes_per_line, &endian);
	game->frame_buffer = (unsigned int *)pixel_data;
	game->buffer_pitch = bytes_per_line / (bits_per_pixel / 8);
	return (0);
}

/*
 * Boot MLX, open the window, create the frame buffer,
 * register input hooks, and enter the event loop.
 */
int	init_mlx_win(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		return (printf("Error: mlx_init\n"), 1);
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "cub3D");
	if (!game->mlx.win_ptr)
		return (printf("Error: mlx_new_window\n"), 1);
	if (create_frame_buffer(game))
		return (1);
	mlx_loop_hook(game->mlx.mlx_ptr, hook_loop, game);
	mlx_hook(game->mlx.win_ptr, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx.win_ptr, 3, 1L << 1, key_release, game);
	mlx_loop(game->mlx.mlx_ptr);
	return (0);
}
