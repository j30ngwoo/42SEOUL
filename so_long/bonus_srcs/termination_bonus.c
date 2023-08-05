/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:28:46 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/26 10:28:57 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_over(t_game_info *game)
{
	ft_putstr("GAME OVER :(\n");
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->img.game_over,
		game->map.x_max * 80 / 2 - 80, game->map.y_max * 80 / 2 - 80);
	game->progress_flag = GAME_END;
}

void	game_clear(t_game_info *game)
{
	ft_putstr("GAME CLEAR! :)\nMovement count - [");
	ft_putnbr(game->player.move_count);
	ft_putstr("]\n");
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->img.game_clear,
		game->map.x_max * 80 / 2 - 80, game->map.y_max * 80 / 2 - 80);
	game->progress_flag = GAME_END;
}
