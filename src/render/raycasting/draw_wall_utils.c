/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:37:57 by canoduran         #+#    #+#             */
/*   Updated: 2026/09/17 17:05:05 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Calculate the position when i start in the texture*/
double	get_tex_start(int draw_start, int line_height, double step)
{
	return ((draw_start - WIN_HEIGHT / 2 + line_height / 2) * step);
}

/*Calculates the vertical step size in the texture for each screen pixel*/
double	get_tex_step(t_tex *tex, int line_height)
{
	return ((double)tex->height / line_height);
}

/*Retrieves the texture pixel color at (tex_x, tex_y), 
darkened if the wall is on the Y-side*/
unsigned int	get_tex_color(t_tex *tex, int tex_x, int tex_y, int side)
{
	unsigned int	color;
	int				tex_width;

	tex_width = tex->line_len / (tex->bpp / 8);
	color = ((unsigned int *)tex->addr)[tex_y * tex_width + tex_x];
	if (side == 1)
		color = (color >> 1) & 0x007F7F7F;
	return (color);
}

/*Calculates the texture column to use, correcting 
for the mirroring effect based on the face hit.*/
int	get_tex_x(t_ray *ray, t_tex *tex, double wall_x)
{
	int		tex_x;
	int		face_vue_de_face;

	tex_x = (int)(wall_x * (double)tex->width);
	face_vue_de_face = (ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 1 && ray->dir_y < 0);
	if (face_vue_de_face)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

/*Calculates the relative position (0 to 1) 
of the ray's impact point on the wall.*/
double	get_wall_x(t_game *game, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->player.y + ray->perp_dist * ray->dir_y;
	else
		wall_x = game->player.x + ray->perp_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}
