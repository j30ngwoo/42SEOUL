/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:41:03 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/26 10:34:48 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_game(t_game_info *game)
{
	draw_map(game);
	draw_player(game);
	draw_items(game);
	game->tic++;
	if (game->tic >= 80)
		game->tic = 0;
	return (0);
}

void	draw_map(t_game_info *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.y_max)
	{
		x = -1;
		while (++x < game->map.x_max)
		{
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.wall, x * 80, y * 80);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.space, x * 80, y * 80);
		}
	}
}

void	draw_player(t_game_info *game)
{
	int	x;
	int	y;

	x = game->player.coord.x;
	y = game->player.coord.y;
	if (game->tic <= 20)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player[0 + game->player.direction], x * 80, y * 80);
	else if (game->tic <= 40)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player[1 + game->player.direction], x * 80, y * 80);
	else if (game->tic <= 60)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player[2 + game->player.direction], x * 80, y * 80);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player[3 + game->player.direction], x * 80, y * 80);
}

void	draw_items(t_game_info *game)
{
	int	x;
	int	y;

	x = game->player.coord.x;
	y = game->player.coord.y;
	y = -1;
	while (++y < game->map.y_max)
	{
		x = -1;
		while (++x < game->map.x_max)
		{
			if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.collectible, x * 80, y * 80);
			if (game->map.map[y][x] == 'E')
			{
				if (game->player.collectibles == game->map.collectibles)
					mlx_put_image_to_window(game->mlx, game->win,
						game->img.exit[1], x * 80, y * 80);
				else
					mlx_put_image_to_window(game->mlx, game->win,
						game->img.exit[0], x * 80, y * 80);
			}
		}
	}
}
