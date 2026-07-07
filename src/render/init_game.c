/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:27:29 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/07/07 16:51:33 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
	main loop called every frame by minilibx
*/
int	hook_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	render_minimap(game);
	return (0);
}

/*
	init minilibx, create window,
	setup hooks, start game loop
*/
int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
		return (1);
	mlx_loop_hook(game->mlx, &hook_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
