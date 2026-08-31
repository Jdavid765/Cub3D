/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:59:58 by canoduran         #+#    #+#             */
/*   Updated: 2026/08/27 17:13:34 by canoduran        ###   ########.fr       */
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
# include "get_next_line.h"

/* -------------------------------------------------------------------------- */
/*                           RENDERER — MACROS                                */
/* -------------------------------------------------------------------------- */

/* Window dimensions in pixels */
# define WIN_WIDTH      1920 /*longeur*/
# define WIN_HEIGHT     1080 /*largeur*/

/* Number of pixels per grid cell on the minimap */
# define MINIMAP_TILE   128
# define MINIMAP_W      384 /*à essayer aussi 644*/
# define MINIMAP_H      384


/* 32-bit colours in ARGB format (0xAARRGGBB) */
# define COLOR_WALL     0xFF444444 /* */
# define COLOR_FLOOR    0xFFCCCCCC /* */
# define COLOR_PLAYER   0xFFFF0000 /*red*/
# define COLOR_DIR      0xFF00FF00 /* green*/
# define COLOR_TESTER   0xFF00F7 /*purple*/
# define COLOR_PLANE    0xFFFFCC00 /*dark yellow*/

/* Movement tuning — units per frame at ~50 FPS */
# define MOVE_SPEED     0.035
# define ROT_SPEED      0.025

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
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	double		x; /*position du joueur sur la grille pos_x et y serait mieux*/
	double		y;
	double		dir_x;/*vecteur de direction du joueur*/
	double		dir_y;
	double		plane_x;/*vecteur perpendiculaire à dir*/
	double		plane_y;
	t_direction	facing;/*orientation du joueur*/
}	t_player;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_dist;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		side;
	int		hit;
}	t_ray;

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
char	**read_all_lines(int fd, int total_lines);
int		build_map(t_game *game, char **raw, int start, int total);
int		split_config_and_map(t_game *game, char **raw, int total_lines);

/* init.c */
void	init(t_game *game);

/* parsing/check_players.c */
int		all_else_if(t_game *game, int y);
int		check_other_player(t_game *game, char letter, int x, int y);

/* parsing/check_map.c */
int		check_player(t_game *game);

/*parsing/parse_elements.c*/
int		pars_identifier(t_game *game, char *line);
int		pars_color(t_color *color, int *set_flag, char *str, int i);
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

/* -------------------------------------------------------------------------- */
/*                           RENDERER — declarations                          */
/* -------------------------------------------------------------------------- */

/* render/player.c */
void	set_north(t_player *player);
void	set_south(t_player *player);
void	set_east(t_player *player);
void	set_west(t_player *player);
void	set_player_direction(t_game *game);

/* render/init_game.c */
int		init_mlx_win(t_game *game);
int		create_frame_buffer(t_game *game);

/* render/hooks.c */
int		hook_loop(void *param);
void	handle_rotation(t_game *game);

/* render/hooks_key.c */
int		key_press(int keycode, void *param);
int		key_release(int keycode, void *param);
void	handle_movement(t_game *game, double move_x, double move_y);
int		is_wall(t_game *game, double x, double y);
void	slide_move(t_game *game, double move_x, double move_y);

/*render/render_3D/draw_wall.c*/
void	correction_fisheye(t_ray *ray, int *draw_start, int *draw_end);
void	fill_wall(t_game *game, t_ray *ray, int x, int draw_start, int draw_end);
void	draw_wall(t_game *game, t_ray *ray, int x);

/*render/render_3D/dda_loop.c*/
void	render_dda(t_game *game);

/* -------------------------------------------------------------------------- */
/*                            MINIMAP — declarations                          */
/* -------------------------------------------------------------------------- */

/*mettre le chemin des dossiers*/
void	draw_minimap_edge(t_game *game);
int		get_cam_offset(double player_pos, int board_size);
int		is_minimap_range(t_game *game, int col, int row);
void	draw_plane_line(t_game *game);
void	put_pixel(t_game *game, int x, int y, unsigned int color);
void	draw_tile(t_game *game, int grid_col, int grid_row,
		unsigned int color);
void	draw_player(t_game *game);
void	draw_all_rays(t_game *game);
void	render_minimap(t_game *game);

/*render/minimap/dda_logic.c*/
double	get_delta_dist(double ray_dir);
void	set_minimap_ray(t_game *game, t_ray *ray,
		double dir_x, double dir_y);
void	draw_ray_line(t_game *game, t_ray *ray);
void	single_ray_loop(t_game *game, double dir_x, double dir_y);

/*render/render_3d/dda_walk.c*/
void	set_step_x(t_game *game, t_ray *ray);
void	set_step_y(t_game *game, t_ray *ray);
void	set_perp_dist(t_ray *ray);
void	dda_walk(t_game *game, t_ray *ray);

#endif
