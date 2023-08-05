/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:02:58 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/25 19:56:02 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coord	make_coord(int x, int y)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

int	**make_int_square(int x, int y)
{
	int		**result;
	int		y_index;

	result = protected_malloc(sizeof(char **) * (y + 1));
	y_index = 0;
	while (y_index < y)
	{
		result[y_index] = protected_malloc(sizeof(char *) * x);
		ft_memset(result[y_index], 0, sizeof(int) * x);
		y_index++;
	}
	result[y_index] = NULL;
	return (result);
}

int	free_char_square(char **square)
{
	int	y;

	y = 0;
	while (square[y])
		free(square[y++]);
	free(square);
	return (0);
}

void	free_int_square(int ***square)
{
	int	y;

	y = 0;
	while ((*square)[y])
		free((*square)[y++]);
	free(*square);
	*square = NULL;
}

void	set_move_coord(t_coord move_coord[4])
{
	move_coord[0].x = 1;
	move_coord[0].y = 0;
	move_coord[1].x = -1;
	move_coord[1].y = 0;
	move_coord[2].x = 0;
	move_coord[2].y = 1;
	move_coord[3].x = 0;
	move_coord[3].y = -1;
}
