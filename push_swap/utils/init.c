/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:11:54 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/17 20:58:01 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	trim_argu(char **av, char ***split_av)
{
	*split_av = ft_strsdup(av + 1);
	if (*split_av == NULL)
		exit(1);
}

void	init_stacks(int ac, t_stacks_info *stacks)
{
	stacks->n = ac - 1;
	stacks->a.arr = NULL;
	stacks->b.arr = NULL;
	stacks->temp = NULL;
	stacks->a.arr = malloc(sizeof(int) * stacks->n);
	if (stacks->a.arr == NULL)
		exit(1);
	stacks->b.arr = malloc(sizeof(int) * stacks->n);
	if (stacks->b.arr == NULL)
		exit(1);
	stacks->temp = malloc(sizeof(int) * stacks->n);
	if (stacks->temp == NULL)
		exit(1);
	stacks->a.head = 0;
	stacks->a.tail = 0;
	stacks->b.head = 0;
	stacks->b.tail = 0;
}

void	convert_av_to_int(char **split_av, t_stacks_info *stacks)
{
	int	av_index;
	int	av_value;

	av_index = 0;
	while (split_av[av_index])
	{
		av_value = ft_atoi(split_av[av_index]);
		stacks->temp[av_index] = av_value;
		stacks->a.arr[av_index] = av_value;
		av_index++;
	}
	stacks->a.size = av_index;
	stacks->b.size = 0;
}
