/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:47:50 by vgabovs           #+#    #+#             */
/*   Updated: 2023/12/18 13:01:49 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <errno.h>
# include "../inc/libft/ft_printf.h"
# include "../minilibx-linux/mlx.h"
// #include <X11/keysym.h>
// #include <X11/X.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLL 'C'
# define ENEMY 'N'

# define IMG_SIZE 64
# define COUNTER 40

# define NONE "\033[0m"
# define GREEN "\033[32m"
# define GRAY "\033[2;37m"
# define CURSIVE "\033[3m"
# define WARNING "\033[33m"
# define RED "\033[31m"

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		width;
	int		height;
	void	*wall_img;
	void	*floor_img;
	void	*player_img_l;
	void	*player_img_r;
	void	*player_img_u;
	void	*player_img_d;
	void	*player_img_ln;
	void	*player_img_rn;
	void	*player_img_un;
	void	*player_img_dn;
	void	*fire1;
	void	*fire2;
	void	*fire3;
	void	*fire4;
	void	*fire5;
	void	*fire6;
	void	*fire7;
	void	*fire8;
	void	*tracks_l;
	void	*tracks_r;
	void	*tracks_u;
	void	*tracks_d;
	void	*enemy_img1;
	void	*enemy_img2;
	void	*collectible_img;
	void	*star_c;
	void	*exit_o_img;
	void	*exit_c_img;
}				t_img;

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
	int		alive;
	int		collected;
	int		count;
	int		move_dir;
	int		prev_x;
	int		prev_y;
	int		movement;
}				t_plr;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		alive;
}				t_enm;

typedef struct s_exit
{
	int		x;
	int		y;
	int		open;
	int		count;
}				t_ext;

typedef struct s_map
{
	int		width;
	int		height;
	int		collectibles;
	t_ext	exit;
	t_enm	enemy;
	char	*line;
	char	**map;
}				t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		counter;
	t_plr	player;
	t_img	img;
	t_map	map;
}				t_game;

int		check_input(char *argv, t_game *game);
void	get_map_size(char *name, t_game *game);
int		check_lines(char *line, t_game *game);
int		check_player_exit_col(t_game *game);
void	initialize(t_game *game);
void	initialize_img(t_game *game);
void	parse_map(char *name, t_game *game);
void	free_map(t_game *game);
void	free_array(char **arr);
char	**ft_map_copy(t_game *game);
void	flood_fill(t_game *game, char **map, int x, int y);
int		map_is_playable(t_game *game);
int		check_name(char *name);
int		check_walls(t_game *game);
void	make_map(t_game *game);
void	textures_init(t_game *game);
void	textures2(t_game *game);
void	textures3(t_game *game);
void	textures4(t_game *game);
int		close_program(t_game *data);
void	put_img(t_game *game, void *img, int x, int y);
void	check_state(t_game *game, int y, int x);
void	keypress_action(t_game *game, int y, int x, int dir);
int		draw_text(t_game *game);
void	car_move(t_game *game);
void	car_move2(t_game *game);
void	move_player(t_game *game, int y, int x, int dir);
int		handle_keypress(int keysym, t_game *game);
void	car_animation(t_game *game, void *img1, void *img2);
void	enemy_loop(t_game *game, int j, int i);
void	explosion_loop(t_game *game, int j, int i);
void	put_right_image(t_game *game, char c, int j, int i);
void	counter(t_game *game);
int		draw_map(t_game *game);
void	make_map(t_game *game);

#endif
