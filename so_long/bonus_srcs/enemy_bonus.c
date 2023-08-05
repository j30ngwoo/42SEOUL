/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:23:21 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/26 13:16:05 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_enemy_img(t_game_info *game)
{
	int	tmp[2];

	game->img.enemy[0] = mlx_xpm_file_to_image(game->mlx,
			"images/zen_chan_L0.xpm", &tmp[0], &tmp[1]);
	game->img.enemy[1] = mlx_xpm_file_to_image(game->mlx,
			"images/zen_chan_L1.xpm", &tmp[0], &tmp[1]);
	game->img.enemy[2] = mlx_xpm_file_to_image(game->mlx,
			"images/zen_chan_L2.xpm", &tmp[0], &tmp[1]);
	game->img.enemy[3] = mlx_xpm_file_to_image(game->mlx,
			"images/zen_chan_L3.xpm", &tmp[0], &tmp[1]);
	game->img.enemy[4] = mlx_xpm_file_to_image(game->mlx,
			"images/zen_chan_R0.xpm", &tmp[0], &tmp[1]);
	game->img.enemy[5] = mlx_xpm_file_to_image(game->mlx,
			"images/zen_chan_R1.xpm", &tmp[0], &tmp[1]);
	game->img.enemy[6] = mlx_xpm_file_to_image(game->mlx,
			"images/zen_chan_R2.xpm", &tmp[0], &tmp[1]);
	game->img.enemy[7] = mlx_xpm_file_to_image(game->mlx,
			"images/zen_chan_R3.xpm", &tmp[0], &tmp[1]);
}

void	init_enemy_coords(t_game_info *game)
{
	int	index;
	int	random_x;
	int	random_y;

	game->enemy_count = game->map.space_count / SPACE_PER_ENEMY;
	if (game->enemy_count > MAX_ENEMY)
		game->enemy_count = MAX_ENEMY;
	srand((unsigned int)time(NULL));
	index = 0;
	while (index < game->enemy_count)
	{
		while (1)
		{
			random_x = rand() % game->map.x_max;
			random_y = rand() % game->map.y_max;
			if (game->map.map[random_y][random_x] == '0'
				&& game->map.map[random_y + 1][random_x] != 'P'
				&& game->map.map[random_y - 1][random_x] != 'P'
				&& game->map.map[random_y][random_x + 1] != 'P'
				&& game->map.map[random_y][random_x - 1] != 'P')
				break ;
		}
		game->enemy[index].coord = make_coord(random_x, random_y);
		game->enemy[index++].direction = L;
	}
}

void	update_enemy(t_game_info *game)
{
	int		enemy_index;

	if (game->tic % SPACE_PER_ENEMY_MOVE != 0)
		return ;
	enemy_index = 0;
	while (enemy_index < game->enemy_count)
	{
		move_enemy(enemy_index, game);
		if (game->enemy[enemy_index].coord.x == game->player.coord.x
			&& game->enemy[enemy_index].coord.y == game->player.coord.y)
			game_over(game);
		enemy_index++;
	}
}

void	move_enemy(int enemy_index, t_game_info *game)
{
	t_coord	move_coord[4];
	t_coord	next_coord;
	int		move_index;

	set_move_coord(move_coord);
	move_index = rand() % 4;
	next_coord.x = game->enemy[enemy_index].coord.x + move_coord[move_index].x;
	next_coord.y = game->enemy[enemy_index].coord.y + move_coord[move_index].y;
	if (game->map.map[next_coord.y][next_coord.x] == '0')
	{
		game->enemy[enemy_index].coord = next_coord;
		if (move_index == 0)
			game->enemy[enemy_index].direction = R;
		if (move_index == 1)
			game->enemy[enemy_index].direction = L;
	}
}

void	draw_enemy(t_game_info *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		if (game->tic <= 20)
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.enemy[0 + game->enemy[i].direction],
				game->enemy[i].coord.x * 80, game->enemy[i].coord.y * 80);
		else if (game->tic <= 40)
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.enemy[1 + game->enemy[i].direction],
				game->enemy[i].coord.x * 80, game->enemy[i].coord.y * 80);
		else if (game->tic <= 60)
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.enemy[2 + game->enemy[i].direction],
				game->enemy[i].coord.x * 80, game->enemy[i].coord.y * 80);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.enemy[3 + game->enemy[i].direction],
				game->enemy[i].coord.x * 80, game->enemy[i].coord.y * 80);
		i++;
	}
}
