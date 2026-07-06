/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:27:29 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/07/06 15:37:31 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


/*  main loop called every frame by MLX42 */
void	hook_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	(void)game;
}


/*
	init mlx42, create window and image,
	 setup hooks, start game loop
*/
int	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!game->mlx)
		return (1);
	game->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->image)
		return (1);
	mlx_image_to_window(game->mlx, game->image, 0, 0);
	mlx_loop_hook(game->mlx, &hook_loop, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
