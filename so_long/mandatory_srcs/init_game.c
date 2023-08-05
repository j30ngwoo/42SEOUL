/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:24:54 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/21 14:11:01 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_values(t_game_info *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->map.x_max * 80, game->map.y_max * 80, "SO_LONG");
	game->tic = 0;
	game->player.move_count = 0;
	game->player.direction = L;
	game->player.collectibles = 0;
	game->player.move_count = 0;
	game->progress_flag = GAME_IN_PROGRESS;
	init_player_img(game);
	init_extra_img(game);
}

void	init_player_img(t_game_info *game)
{
	int	tmp[2];

	game->img.player[0] = mlx_xpm_file_to_image(game->mlx,
			"images/bubblun_L0.xpm", &tmp[0], &tmp[1]);
	game->img.player[1] = mlx_xpm_file_to_image(game->mlx,
			"images/bubblun_L1.xpm", &tmp[0], &tmp[1]);
	game->img.player[2] = mlx_xpm_file_to_image(game->mlx,
			"images/bubblun_L2.xpm", &tmp[0], &tmp[1]);
	game->img.player[3] = mlx_xpm_file_to_image(game->mlx,
			"images/bubblun_L3.xpm", &tmp[0], &tmp[1]);
	game->img.player[4] = mlx_xpm_file_to_image(game->mlx,
			"images/bubblun_R0.xpm", &tmp[0], &tmp[1]);
	game->img.player[5] = mlx_xpm_file_to_image(game->mlx,
			"images/bubblun_R1.xpm", &tmp[0], &tmp[1]);
	game->img.player[6] = mlx_xpm_file_to_image(game->mlx,
			"images/bubblun_R2.xpm", &tmp[0], &tmp[1]);
	game->img.player[7] = mlx_xpm_file_to_image(game->mlx,
			"images/bubblun_R3.xpm", &tmp[0], &tmp[1]);
}

void	init_extra_img(t_game_info *game)
{
	int	tmp[2];

	game->img.space = mlx_xpm_file_to_image(game->mlx,
			"images/space4.xpm", &tmp[0], &tmp[1]);
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"images/wall5.xpm", &tmp[0], &tmp[1]);
	game->img.exit[0] = mlx_xpm_file_to_image(game->mlx,
			"images/exit0.xpm", &tmp[0], &tmp[1]);
	game->img.exit[1] = mlx_xpm_file_to_image(game->mlx,
			"images/exit1.xpm", &tmp[0], &tmp[1]);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx,
			"images/cherry.xpm", &tmp[0], &tmp[1]);
	game->img.game_over = mlx_xpm_file_to_image(game->mlx,
			"images/game_over.xpm", &tmp[0], &tmp[1]);
	game->img.game_clear = mlx_xpm_file_to_image(game->mlx,
			"images/you_win.xpm", &tmp[0], &tmp[1]);
}
