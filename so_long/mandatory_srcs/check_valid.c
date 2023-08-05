/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:47:23 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/30 15:21:21 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_berfile(char *filename)
{
	int	index;

	index = 0;
	while (filename[index])
		index++;
	if (index < 4)
		exit_with_message("File is not .ber extension\n");
	if (filename[--index] != 'r')
		exit_with_message("File is not .ber extension\n");
	if (filename[--index] != 'e')
		exit_with_message("File is not .ber extension\n");
	if (filename[--index] != 'b')
		exit_with_message("File is not .ber extension\n");
	if (filename[--index] != '.')
		exit_with_message("File is not .ber extension\n");
}

void	check_chars_in_map(t_map_info *map_info)
{
	t_coord	index;
	char	now_char;

	index.y = 0;
	while (index.y < map_info->y_max)
	{
		index.x = 0;
		while (index.x < map_info->x_max + 1)
		{
			now_char = map_info->map[index.y][index.x];
			check_char_valid(now_char, index.x, index.y, map_info);
			index.x++;
		}
		if (index.x != map_info->x_max + 1)
			exit_with_message("Invalid map\n");
		index.y++;
	}
}

void	check_char_valid(char c, int x_index, int y_index, t_map_info *map_info)
{
	if (x_index < map_info->x_max
		&& c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		exit_with_message("Invalid map\n");
	if (is_side(x_index, y_index, map_info) && c != '1')
		exit_with_message("Invalid map\n");
	if (x_index == map_info->x_max && y_index < map_info->y_max - 1
		&& c != '\n')
		exit_with_message("Invalid map\n");
	if ((x_index == map_info->x_max + 1) && c != '\0')
		exit_with_message("Invalid map\n");
	if (x_index == map_info->x_max && y_index == map_info->y_max - 1
		&& c != '\0')
		exit_with_message("Invalid map\n");
}

int	is_side(int x, int y, t_map_info *map_info)
{
	if ((y == 0 || y == map_info->y_max - 1) && x < map_info->x_max)
		return (1);
	else if (x == 0 || x == map_info->x_max - 1)
		return (1);
	else
		return (0);
}

void	check_exit_and_position_only_one_exist(t_map_info *map_info)
{
	t_coord	index;
	char	now_char;
	int		exit_count;
	int		position_count;

	exit_count = 0;
	position_count = 0;
	index.y = 0;
	while (index.y < map_info->y_max)
	{
		index.x = 0;
		while (index.x < map_info->x_max)
		{
			now_char = map_info->map[index.y][index.x];
			if (now_char == 'E')
				exit_count++;
			if (now_char == 'P')
				position_count++;
			index.x++;
		}
		index.y++;
	}
	if (exit_count != 1 || position_count != 1)
		exit_with_message("Invalid map\n");
}
