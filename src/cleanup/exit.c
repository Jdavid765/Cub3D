/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:30:00 by pucci17pink        #+#    #+#             */
/*   Updated: 2026/09/07 14:30:00 by pucci17pink       ###   ########.fr       */
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
	free_textures(game);
	free_mlx(game);
}
