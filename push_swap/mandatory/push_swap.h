/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:35:27 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/26 08:49:30 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define A 0
# define B 1
# include "../opers/opers.h"

// pivot
t_int_pair	find_two_pivots(t_stacks_info *stacks);
void		quicksort(int arr_head, int arr_tail, int *arr, int arr_max);
void		divide_into_three(t_int_pair pivots, t_stacks_info *stacks);

// over 6
void		over_six_process(t_stacks_info *stacks);
void		exec_min_opers(t_oper_counter min_opers, t_stacks_info *stacks);
void		last_rotate(t_stacks_info *stacks);

// under 6
void		under_six_process(t_stacks_info *stacks);
void		divide_in_two(int pivot, t_stacks_info *stacks);
void		*set_sx(int which_stack);
void		*set_rrx(int which_stack);
t_stack		*set_stack(int which_stack, t_stacks_info *stacks);

// sort 2~3
void		ascending_sort_three(t_stacks_info *stacks, int which_stack);
void		descending_sort_three(t_stacks_info *stacks, int which_stack);
void		ascending_sort_two(t_stacks_info *stacks, int which_stack);
void		descending_sort_two(t_stacks_info *stacks, int which_stack);

#endif