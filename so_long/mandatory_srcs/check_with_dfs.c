/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_with_dfs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:54:07 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/08/02 16:32:04 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_accessible_space(t_game_info *game)
{
	t_map_element_count	count;
	t_coord				init_coord;
	int					**visited;

	count.collectible = 0;
	count.exit = 0;
	count.position = 0;
	init_coord = make_coord(game->player.coord.x, game->player.coord.y);
	visited = make_int_square(game->map.x_max, game->map.y_max);
	dfs_space(init_coord, &count, &(game->map), visited);
	if (count.exit != 1 || count.position != 1
		|| count.collectible != game->map.collectibles)
		exit_with_message("Invalid map\n");
	free_int_square(&visited);
}

void	dfs_space(t_coord coord, t_map_element_count *cep_count,
		t_map_info *map_info, int **visited)
{
	char	now_char;

	now_char = map_info->map[coord.y][coord.x];
	if (now_char == '1' || visited[coord.y][coord.x])
		return ;
	visited[coord.y][coord.x] = 1;
	if (now_char == 'C')
		cep_count->collectible++;
	else if (now_char == 'E')
		cep_count->exit++;
	else if (now_char == 'P')
		cep_count->position++;
	dfs_space(make_coord(coord.x + 1, coord.y), cep_count, map_info, visited);
	dfs_space(make_coord(coord.x - 1, coord.y), cep_count, map_info, visited);
	dfs_space(make_coord(coord.x, coord.y + 1), cep_count, map_info, visited);
	dfs_space(make_coord(coord.x, coord.y - 1), cep_count, map_info, visited);
}
