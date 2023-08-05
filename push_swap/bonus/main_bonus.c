/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:39:57 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/18 11:27:38 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	if (!exec_oper(&stacks))
		return (free_stacks(stacks), print_error());
	if (is_stack_sorted(stacks.a, stacks.n) && stacks.b.size == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (free_stacks(stacks));
}
