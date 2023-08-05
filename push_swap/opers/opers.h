/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:38:17 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/17 20:49:54 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERS_H
# define OPERS_H

# define NO_PRINT 0
# define PRINT 1

# include "../utils/utils.h"

//opers
void		pa(t_stacks_info *stacks, int is_print);
void		pb(t_stacks_info *stacks, int is_print);

void		rra(t_stacks_info *stacks, int is_print);
void		rrb(t_stacks_info *stacks, int is_print);
void		rrr(t_stacks_info *stacks, int is_print);

void		ra(t_stacks_info *stacks, int is_print);
void		rb(t_stacks_info *stacks, int is_print);
void		rr(t_stacks_info *stacks, int is_print);

void		sa(t_stacks_info *stacks, int is_print);
void		sb(t_stacks_info *stacks, int is_print);
void		ss(t_stacks_info *stacks, int is_print);

#endif