/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 15:19:53 by canoduran         #+#    #+#             */
/*   Updated: 2026/09/07 16:36:37 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
	
int	load_texture(t_game *game, t_tex *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx.mlx_ptr, path,
			&tex->width, &tex->height);
	if (!tex->img)
		return (printf("Error: texture not loaded %s \n", path), 1);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
	if (!tex->addr)
		return (printf("Error: texture addr %s \n", path), 1);
	return (0);
}
	
int	load_textures(t_game *game)
{
	if (load_texture(game, &game->tex[TEX_NO], game->texture.no))
		return (1);
	if (load_texture(game, &game->tex[TEX_SO], game->texture.so))
		return (1);
	if (load_texture(game, &game->tex[TEX_EA], game->texture.ea))
		return (1);
	if (load_texture(game, &game->tex[TEX_WE], game->texture.we))
		return (1);
	return (0);
}