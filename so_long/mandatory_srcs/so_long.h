/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:55:55 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/30 15:23:24 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

# define TIC 80
# define L 0
# define R 4

# define SPACE_PER_ENEMY 20
# define MAX_ENEMY 10
# define SPACE_PER_ENEMY_MOVE 40

# define GAME_IN_PROGRESS 0
# define GAME_END 1

typedef unsigned long long	t_ull;
typedef char				t_byte;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map_info
{
	char		**map;
	int			x_max;
	int			y_max;
	int			space_count;
	int			collectibles;
}	t_map_info;

typedef struct s_enemy_info
{
	int		n;
	int		last_tic;
	int		direction;
	t_coord	coord;
}	t_enemy_info;

typedef struct s_player_info
{
	int		n;
	int		direction;
	int		collectibles;
	int		move_count;
	t_coord	coord;
}	t_player_info;

typedef struct s_img_info
{
	void	*player[8];
	void	*enemy[8];
	void	*space;
	void	*wall;
	void	*collectible;
	void	*exit[2];
	void	*game_over;
	void	*game_clear;
}	t_img_info;

typedef struct s_game_info
{
	int				progress_flag;
	void			*mlx;
	void			*win;
	t_ull			tic;
	t_map_info		map;
	t_img_info		img;
	int				enemy_count;
	t_enemy_info	enemy[MAX_ENEMY];
	t_player_info	player;
}	t_game_info;

typedef struct s_map_element_count
{
	int	collectible;
	int	exit;
	int	position;
}	t_map_element_count;

// init
void	init_map_values(t_game_info *game);
void	parse_map(char *map_file, t_map_info *map_info);
void	init_map_info(t_game_info *game);

// check_valid
void	check_berfile(char *filename);
void	check_chars_in_map(t_map_info *map_info);
void	check_char_valid(char c, int x_index, int y_index,
			t_map_info *map_info);
int		is_side(int x, int y, t_map_info *map_info);
void	check_exit_and_position_only_one_exist(t_map_info *map_info);

// dfs
void	check_accessible_space(t_game_info *game);
void	dfs_space(t_coord coord, t_map_element_count *cep_count,
			t_map_info *map_info, int **visited);

// game init
void	init_game_values(t_game_info *game);
void	init_player_img(t_game_info *game);
void	init_enemy_img(t_game_info *game);
void	init_extra_img(t_game_info *game);
void	init_enemy_coords(t_game_info *game);

// game render
int		render_game(t_game_info *game);
void	draw_map(t_game_info *game);
void	draw_player(t_game_info *game);
void	draw_items(t_game_info *game);

// key input process
int		key_input_proc(int keycode, t_game_info *game);
void	update_player_direction(int keycode, t_game_info *game);
void	update_player_position(int keycode, t_game_info *game);
void	update_collectible(t_game_info *game);

// utils
t_coord	make_coord(int x, int y);
int		**make_int_square(int x, int y);
int		free_char_square(char **square);
void	free_int_square(int ***square);
void	set_move_coord(t_coord move_coord[4]);

// protected_func
ssize_t	protected_read(int fildes, void *buf, size_t nbyte);
int		protected_open(const char *path, int oflag);
void	*protected_malloc(size_t size);
void	*double_ptr_realloc(char **ptr, size_t size);
char	*protected_ntoa(int n);

// termi
void	perror_exit(void);
void	exit_with_message(char *message);
int		game_shutdown(void);

#endif