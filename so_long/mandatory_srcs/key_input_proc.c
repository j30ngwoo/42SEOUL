/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_proc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:28:44 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/26 09:46:06 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_input_proc(int keycode, t_game_info *game)
{
	int	prev_move_count;

	if (game->progress_flag != GAME_IN_PROGRESS)
		return (0);
	if (keycode == ESC)
		exit(0);
	prev_move_count = game->player.move_count;
	update_player_direction(keycode, game);
	update_player_position(keycode, game);
	update_collectible(game);
	if (prev_move_count != game->player.move_count)
		ft_putnbr_nl(game->player.move_count);
	if (game->player.collectibles == game->map.collectibles
		&& game->map.map[game->player.coord.y][game->player.coord.x] == 'E')
		game_shutdown();
	return (0);
}

void	update_player_direction(int keycode, t_game_info *game)
{
	if (keycode == A)
		game->player.direction = L;
	if (keycode == D)
		game->player.direction = R;
}

void	update_player_position(int keycode, t_game_info *game)
{
	int	prev_x;
	int	prev_y;

	prev_x = game->player.coord.x;
	prev_y = game->player.coord.y;
	if (keycode == A && game->map.map[prev_y][prev_x - 1] != '1')
	{
		game->player.coord.x--;
		game->player.move_count++;
	}
	else if (keycode == S && game->map.map[prev_y + 1][prev_x] != '1')
	{
		game->player.coord.y++;
		game->player.move_count++;
	}
	else if (keycode == D && game->map.map[prev_y][prev_x + 1] != '1')
	{
		game->player.coord.x++;
		game->player.move_count++;
	}
	else if (keycode == W && game->map.map[prev_y - 1][prev_x] != '1')
	{
		game->player.coord.y--;
		game->player.move_count++;
	}
}

void	update_collectible(t_game_info *game)
{
	int	now_x;
	int	now_y;

	now_x = game->player.coord.x;
	now_y = game->player.coord.y;
	if (game->map.map[now_y][now_x] == 'C')
	{
		game->player.collectibles++;
		game->map.map[now_y][now_x] = '0';
	}
}
