/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:30:00 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/07/07 17:30:00 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define KEY_ESC 65307

/*  close window and exit cleanly on ESC press */
int	key_handler(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}
