/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 21:39:37 by canoduran         #+#    #+#             */
/*   Updated: 2026/09/20 20:18:40 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Release everything the game allocated ,in one place.
 * Called on ESC and on any early error in main.
 */
void	exit_all(t_game *game)
{
	free_grid(game);
	free(game->texture.no);
	free(game->texture.so);
	free(game->texture.we);
	free(game->texture.ea);
}

int	close_game(int keycode, void *param)
{
	t_game	*game;
	int		i;

	(void)keycode;
	game = (t_game *)param;
	i = 0;
	while (i < TEX_COUNT)
	{
		if (game->tex[i].img)
			mlx_destroy_image(game->mlx.mlx_ptr, game->tex[i].img);
		i++;
	}
	if (game->frame_image)
		mlx_destroy_image(game->mlx.mlx_ptr, game->frame_image);
	if (game->mlx.win_ptr)
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	if (game->mlx.mlx_ptr)
	{
		mlx_destroy_display(game->mlx.mlx_ptr);
		free(game->mlx.mlx_ptr);
	}
	ft_exit(game);
	exit(0);
}
