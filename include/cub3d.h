/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:59:58 by canoduran         #+#    #+#             */
/*   Updated: 2026/06/20 22:02:02 by canoduran        ###   ########.fr       */
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
	t_map			map;
	t_player		player;
	t_floodfil		floodfil;
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

/*parsing/floodfil.c*/
int		cpy_the_map(t_game *game);
int		floodfil(t_game *game, int x, int y);

/*clear/clear_core.c*/
// void	ft_exit(t_game *game);

/*clear/utils.c*/
// void	free_table(t_game *game);

#endif