/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:59:58 by canoduran         #+#    #+#             */
/*   Updated: 2026/07/23 18:24:57 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../get-next-line/get_next_line.h"

typedef enum e_car_points
{
	none,
	north,
	south,
	east,
	west
}		t_car_points;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_texture;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	char	**grid;
	char	**cpy_grid;
}		t_map;

typedef struct s_player
{
	int				x;
	int				y;
	t_car_points	cardinal;
}		t_player;

typedef struct s_floodfil
{
	int		status;
	char	letter;
}		t_floodfil;

typedef struct s_game
{
	char			*filename;
	int				count_line;
	int				floor_set;
	int				ceiling_set;
	t_map			map;
	t_player		player;
	t_floodfil		floodfil;
	t_texture		texture;
	t_color			floor_color;
	t_color			ceiling_color;
}		t_game;

/*check_filename.c*/
int		check_filename(char *line, char *verif, t_game *game);

/*take_map.c*/
int		open_file(t_game *filename);
int		count_l(int fd);

/*init.c*/
void	init(t_game *game);

/*parsing/utils.c*/
int		all_else_if(t_game *game, int y);
int		check_other_player(t_game *game, char letter, int x, int y);

/*parsing/parsing.c*/
int		check_player(t_game *game);

/*parsing/parse_texture.c*/
int		pars_identifier(t_game *game, char *line);
int		pars_color(t_color *color, int *set_flag, char *str);
int		pars_texture(char **dest, char *path);
int		pars_int(char **str, int *value);

/*parsing/parse_utils.c*/
int		is_empty_line(char *line);
int		is_config_line(char *line);
int		free_table(char **raw, int count);
int		all_configuration_found(t_game *game);

/*parsing/floodfil.c*/
int		cpy_the_map(t_game *game);
int		floodfil(t_game *game, int x, int y);

/*clear/clear_core.c*/
void	ft_exit(t_game *game);

/*clear/utils.c*/
void	free_grid(t_game *game);
void	free_cpygrid(t_game *game, int position);

#endif