/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:55:41 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/30 15:22:57 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_hook(game.win, 17, 0, game_shutdown, 0);
	mlx_key_hook(game.win, key_input_proc, &(game));
	mlx_loop_hook(game.mlx, render_game, &(game));
	mlx_loop(game.mlx);
	return (0);
}
