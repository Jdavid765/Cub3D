/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:16:12 by canoduran         #+#    #+#             */
/*   Updated: 2026/09/20 20:05:42 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Calculate the on-screen height of the wall column*/
int	get_line_height(t_ray *ray)
{
	int	height;

	height = (int)(WIN_HEIGHT / ray->perp_dist);
	if (height < 1)
		height = 1;
	return (height);
}

/* Calcule draw_start/draw_end*/
void	correction_fisheye(t_ray *ray, int *draw_start, int *draw_end)
{
	int	line_height;

	line_height = get_line_height(ray);
	*draw_start = WIN_HEIGHT / 2 - line_height / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = WIN_HEIGHT / 2 + line_height / 2;
	if (*draw_end >= WIN_HEIGHT)
		*draw_end = WIN_HEIGHT - 1;
}

t_tex	*choose_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (&game->tex[TEX_EA]);
		return (&game->tex[TEX_WE]);
	}
	if (ray->dir_y > 0)
		return (&game->tex[TEX_SO]);
	return (&game->tex[TEX_NO]);
}

/* Draws the textured wall of column x, pixel by pixel */
void	draw_wall_strip(t_game *game, t_ray *ray, int x, int *range)
{
	t_tex	*tex;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		y;

	tex = choose_texture(game, ray);
	tex_x = get_tex_x(ray, tex, get_wall_x(game, ray));
	step = get_tex_step(tex, get_line_height(ray));
	tex_pos = get_tex_start(range[0], get_line_height(ray), step);
	y = range[0];
	while (y <= range[1])
	{
		put_pixel(game, x, y, get_tex_color(tex, tex_x,
				(int)tex_pos % tex->height, ray->side));
		tex_pos += step;
		y++;
	}
}

/* Draws the x-column: sky, textured wall, then ground */
void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int	draw_start;
	int	draw_end;
	int	y;
	int	range[2];

	correction_fisheye(ray, &draw_start, &draw_end);
	range[0] = draw_start;
	range[1] = draw_end;
	y = 0;
	while (y < draw_start)
	{
		put_pixel(game, x, y, color_to_int(game->ceiling_color));
		y++;
	}
	draw_wall_strip(game, ray, x, range);
	y = draw_end + 1;
	while (y < WIN_HEIGHT)
	{
		put_pixel(game, x, y, color_to_int(game->floor_color));
		y++;
	}
}
