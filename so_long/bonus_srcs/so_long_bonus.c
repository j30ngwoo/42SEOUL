/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:27:23 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/08/03 17:22:22 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_game_info	game;

	if (ac != 2)
		exit_with_message("Parameter Error\n");
	check_berfile(av[1]);
	init_map_values(&game);
	parse_map(av[1], &(game.map));
	init_map_info(&game);
	check_chars_in_map(&(game.map));
	check_exit_and_position_only_one_exist(&(game.map));
	check_accessible_space(&game);
	init_game_values(&game);
	init_enemy_img(&game);
	init_enemy_coords(&game);
	game.map.map[game.player.coord.y][game.player.coord.x] = '0';
	mlx_hook(game.win, 17, 0, game_shutdown, 0);
	mlx_key_hook(game.win, key_input_proc_bonus, &(game));
	mlx_loop_hook(game.mlx, render_game_bonus, &(game));
	mlx_loop(game.mlx);
	return (0);
}

int	render_game_bonus(t_game_info *game)
{
	if (game->progress_flag == GAME_END)
	{
		sleep(2);
		exit(0);
	}
	draw_map(game);
	draw_move_count(game);
	draw_player(game);
	draw_items(game);
	update_enemy(game);
	if (game->progress_flag == GAME_IN_PROGRESS)
		draw_enemy(game);
	game->tic++;
	if (game->tic >= 80)
		game->tic = 0;
	return (0);
}

void	draw_move_count(t_game_info *game)
{
	char	*move_int_str;

	move_int_str = protected_ntoa(game->player.move_count);
	mlx_string_put(game->mlx, game->win, 10, 5, 0x00000000, move_int_str);
	free(move_int_str);
}

int	key_input_proc_bonus(int keycode, t_game_info *game)
{
	if (keycode == ESC)
		game_over(game);
	update_player_direction(keycode, game);
	update_player_position(keycode, game);
	update_collectible(game);
	check_game_over(game);
	return (0);
}

void	check_game_over(t_game_info *game)
{
	int	now_x;
	int	now_y;
	int	i;

	now_x = game->player.coord.x;
	now_y = game->player.coord.y;
	i = 0;
	while (i < game->enemy_count)
	{
		if (now_x == game->enemy[i].coord.x && now_y == game->enemy[i].coord.y)
			game_over(game);
		i++;
	}
	if (game->map.map[now_y][now_x] == 'E' &&
		game->player.collectibles == game->map.collectibles)
		game_clear(game);
}
