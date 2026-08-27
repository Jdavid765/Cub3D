/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_dda_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 15:26:01 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/08/27 17:20:53 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_dda(t_game *game)
{
	t_ray	ray;
	int		x;
	double	fake_dist;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ft_bzero(&ray, sizeof(t_ray));
		fake_dist = 3.0 + fabs((double)(x - WIN_WIDTH / 2))
			/ (WIN_WIDTH / 2.0) * 6.0;
		if (x % 40 < 20)
			ray.side = 0;
		else
			ray.side = 1;
		if (ray.side == 0)
		{
			ray.side_dist_x = fake_dist;
			ray.delta_dist_x = 0;
		}
		else
		{
			ray.side_dist_y = fake_dist;
			ray.delta_dist_y = 0;
		}
		draw_wall(game, &ray, x);
		x++;
	}
}