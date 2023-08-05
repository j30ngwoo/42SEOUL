/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:55:36 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/24 16:08:13 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks_info	stacks;
	char			**split_av;

	if (ac < 2)
		return (0);
	trim_argu(av, &split_av);
	check_arg_avail(split_av);
	init_stacks(ac, &stacks);
	convert_av_to_int(split_av, &stacks);
	free_strs(split_av);
	if (is_there_duplicates(stacks.temp, stacks.n))
		return (free_stacks(stacks), print_error());
	if (is_stack_sorted(stacks.a, stacks.n))
		return (free_stacks(stacks));
	quicksort(0, stacks.n - 1, stacks.temp, stacks.n);
	if (ac <= 6)
		under_six_process(&stacks);
	else
		over_six_process(&stacks);
	return (free_stacks(stacks));
}
