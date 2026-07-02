/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:59:58 by canoduran         #+#    #+#             */
/*   Updated: 2026/06/15 16:47:43 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../get-next-line/get_next_line.h"

# define WIDTH  1920
# define HEIGHT 1080

typedef enum e_car_points
{
	none,
	north,
	south,
	east,
	west
}		t_car_points;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}		t_map;

typedef struct s_player
{
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	t_car_points	cardinal;
}		t_player;

typedef struct s_game
{
	char			*filename;
	t_map			map;
	t_player		player;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	int				floor_color;
	int				ceiling_color;
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_texture_t	*t_no;
	mlx_texture_t	*t_so;
	mlx_texture_t	*t_ea;
	mlx_texture_t	*t_we;
}		t_game;

/*check_filename.c*/
int		check_filename(char *line, char *verif, t_game *game);

/*take_map.c*/
int		open_file(t_game *filename);
int		count_l(int fd);
int		add_map_in_grid(t_game *game, int count_lines, int fd);

/*init.c*/
void	init(t_game *game);

/*parsing/utils.c*/
int		all_else_if(t_game *game, int y);
int		check_other_player(t_game *game, char letter, int x, int y);

/*parsing/parsing.c*/
int		check_player(t_game *game);

#endif
