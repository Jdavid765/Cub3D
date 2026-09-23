/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 21:39:37 by canoduran         #+#    #+#             */
/*   Updated: 2026/09/23 03:16:01 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(t_game *game)
{
	free_grid(game);
	free_textures(game);
	free_mlx(game);
}

void	exit_all(t_game *game)
{
	free_grid(game);
	free(game->texture.no);
	free(game->texture.so);
	free(game->texture.we);
	free(game->texture.ea);
}

int	close_game(void *param)
{
	ft_exit((t_game *)param);
	exit(0);
}
