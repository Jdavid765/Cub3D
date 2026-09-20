/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:30:00 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/09/20 20:56:19 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_grid(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->count_line)
	{
		if (game->map.grid)
			free(game->map.grid[i]);
		if (game->map.cpy_grid)
			free(game->map.cpy_grid[i]);
		i++;
	}
	free(game->map.grid);
	free(game->map.cpy_grid);
}

void	free_cpygrid(t_game *game, int position)
{
	int	i;

	i = 0;
	while (i < position)
		free(game->map.cpy_grid[i++]);
	free(game->map.cpy_grid);
}

/*
 * Free the four texture paths and, if already loaded, destroy
 * the matching MLX images.
 */
void	free_textures(t_game *game)
{
	if (game->texture.no)
		free(game->texture.no);
	if (game->texture.so)
		free(game->texture.so);
	if (game->texture.we)
		free(game->texture.we);
	if (game->texture.ea)
		free(game->texture.ea);
	if (game->tex[TEX_NO].img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->tex[TEX_NO].img);
	if (game->tex[TEX_SO].img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->tex[TEX_SO].img);
	if (game->tex[TEX_WE].img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->tex[TEX_WE].img);
	if (game->tex[TEX_EA].img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->tex[TEX_EA].img);
}

/*
 * Destroy the MLX frame image, window and display.
 */
void	free_mlx(t_game *game)
{
	if (game->frame_image)
		mlx_destroy_image(game->mlx.mlx_ptr, game->frame_image);
	if (game->mlx.win_ptr)
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	if (game->mlx.mlx_ptr)
		mlx_destroy_display(game->mlx.mlx_ptr);
}
