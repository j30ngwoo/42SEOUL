/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:15:14 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/30 15:27:36 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_values(t_game_info *game)
{
	game->map.map = NULL;
	game->map.x_max = 0;
	game->map.y_max = 0;
	game->map.space_count = 0;
	game->map.collectibles = 0;
}

void	parse_map(char *map_file, t_map_info *map_info)
{
	int		map_fd;
	char	*row;

	map_fd = protected_open(map_file, O_RDONLY);
	while (1)
	{
		row = get_next_line(map_fd);
		if (row == NULL)
			break ;
		map_info->y_max++;
		map_info->map = double_ptr_realloc(map_info->map, map_info->y_max + 1);
		map_info->map[map_info->y_max - 1] = row;
	}
	if (map_info->map == NULL)
		exit_with_message("Invalid map\n");
}

void	init_map_info(t_game_info *game)
{
	t_coord	index;
	char	now_char;

	game->map.x_max = ft_strlen(game->map.map[0]) - 1;
	index.y = 0;
	while (index.y < game->map.y_max)
	{
		index.x = 0;
		while (index.x < game->map.x_max && game->map.map[index.y][index.x])
		{
			now_char = game->map.map[index.y][index.x];
			if (now_char == 'C')
				game->map.collectibles++;
			if (now_char == 'P')
				game->player.coord = make_coord(index.x, index.y);
			if (now_char == '0')
				game->map.space_count++;
			index.x++;
		}
		index.y++;
	}
	if (game->map.collectibles < 1)
		exit_with_message("Invalid map\n");
}
