/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:02:04 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/07/06 15:17:05 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*  set player looking north */
void	set_north(t_player *p)
{
	p->dir_x = 0;
	p->dir_y = -1;
	p->plane_x = 0.66;
	p->plane_y = 0;
}

/*  set player looking south */
void	set_south(t_player *p)
{
	p->dir_x = 0;
	p->dir_y = 1;
	p->plane_x = -0.66;
	p->plane_y = 0;
}

/*  set player looking east */
void	set_east(t_player *p)
{
	p->dir_x = 1;
	p->dir_y = 0;
	p->plane_x = 0;
	p->plane_y = 0.66;
}

/*  set player looking west */
void	set_west(t_player *p)
{
	p->dir_x = -1;
	p->dir_y = 0;
	p->plane_x = 0;
	p->plane_y = -0.66;
}

/* choose direction function based on cardinal orientation */
void	set_player_dir(t_game *game)
{
	if (game->player.cardinal == north)
		set_north(&game->player);
	else if (game->player.cardinal == south)
		set_south(&game->player);
	else if (game->player.cardinal == east)
		set_east(&game->player);
	else if (game->player.cardinal == west)
		set_west(&game->player);
}
