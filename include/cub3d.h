/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:59:58 by canoduran         #+#    #+#             */
/*   Updated: 2026/07/23 17:20:08 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"
/* # include "get_next_line.h"  — TODO: enable when GNL will be added*/

/* -------------------------------------------------------------------------- */
/*                           RENDERER — MACROS                                */
/* -------------------------------------------------------------------------- */

/* Window dimensions in pixels */
# define WIN_WIDTH      1920
# define WIN_HEIGHT     1080

/* Number of pixels per grid cell on the minimap */
# define MINIMAP_TILE   200

/* 32-bit colours in ARGB format (0xAARRGGBB) */
# define COLOR_WALL     0xFF444444 /* */
# define COLOR_FLOOR    0xFFCCCCCC /* */
# define COLOR_PLAYER   0xFFFF0000 /*red*/
# define COLOR_DIR      0xFF00FF00 /* green*/

/* Movement tuning — units per frame at ~50 FPS */
# define MOVE_SPEED     0.03
# define ROT_SPEED      0.02

/* X11 keycodes */
# define KEY_W          119
# define KEY_A          97
# define KEY_S          115
# define KEY_D          100
# define KEY_ESC        65307
# define KEY_LEFT       65361
# define KEY_RIGHT      65363

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_keys
{
	bool	forward;
	bool	backward;
	bool	move_left;
	bool	move_right;
	bool	rotate_left;
	bool	rotate_right;
}	t_keys;

typedef enum e_direction
{
	DIR_NONE,
	DIR_NORTH,
	DIR_SOUTH,
	DIR_EAST,
	DIR_WEST
}	t_direction;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	double		x; /*position du joueur sur la grille*/
	double		y;
	double		dir_x;/*vecteur de direction du joueur*/
	double		dir_y;
	double		plane_x;/*vecteur perpendiculaire à dir*/
	double		plane_y;
	t_direction	facing;/*orientation du joueur*/
}	t_player;

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
	t_mlx			mlx;
	void			*frame_image;
	unsigned int	*frame_buffer;
	int				buffer_pitch; /*buffer de l'image a taille réele avec les pixels poubelle*/
	void			*t_no;
	void			*t_so;
	void			*t_ea;
	void			*t_we;
	t_keys			keys;
}	t_game;

/* -------------------------------------------------------------------------- */
/*                           PARSING — declarations                           */
/* -------------------------------------------------------------------------- */

/* check_filename.c */
int		check_filename(char *line, char *verif, t_game *game);

/* take_map.c */
int		open_file(t_game *filename);
int		count_l(int fd);
int		add_map_in_grid(t_game *game, int count_lines, int fd);

/* init.c */
void	init(t_game *game);

/* parsing/utils.c */
int		all_else_if(t_game *game, int y);
int		check_other_player(t_game *game, char letter, int x, int y);

/* parsing/parsing.c */
int		check_player(t_game *game);

/* -------------------------------------------------------------------------- */
/*                           RENDERER — declarations                          */
/* -------------------------------------------------------------------------- */

/* render/player.c */
void	set_north(t_player *player);
void	set_south(t_player *player);
void	set_east(t_player *player);
void	set_west(t_player *player);
void	set_player_direction(t_game *game);

/* render/init_mlx_win.c */
int		init_mlx_win(t_game *game);
int		create_frame_buffer(t_game *game);

/* render/minimap.c */
void	render_minimap(t_game *game);

/* render/hooks.c */
int		hook_loop(void *param);

/* render/hooks_key.c */
int		key_press(int keycode, void *param);
int		key_release(int keycode, void *param);
void	handle_movement(t_game *game, double move_x, double move_y);

#endif
