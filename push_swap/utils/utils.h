/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:43:11 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/26 17:50:23 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	head;
	int	tail;
}	t_stack;

typedef struct s_stacks_info
{
	t_stack	a;
	t_stack	b;
	int		*temp;
	int		n;
}	t_stacks_info;

typedef struct s_oper_counter
{
	int	rb;
	int	rrb;
	int	ra;
	int	rra;
	int	total;
}	t_oper_counter;

//control_stack
void		push_front(int value, int arr_max, t_stack *stack);
void		push_back(int value, int arr_max, t_stack *stack);
int			pop_front(int arr_max, t_stack *stack);
int			pop_back(int arr_max, t_stack *stack);

// availability
void		check_arg_avail(char **av);
int			is_there_duplicates(int *arr, int arr_size);
int			is_stack_sorted(t_stack stack, int arr_max);

//control_index
int			increase_idx(int arr_max, int prev_idx);
int			decrease_idx(int arr_max, int prev_idx);
int			length_from_head(int index, int arr_size, t_stack stack);
int			max_value_index_in_stack(int arr_max, t_stack stack);
int			min_value_index_in_stack(int arr_max, t_stack stack);

// init
void		trim_argu(char **av, char ***split_av);
void		init_stacks(int ac, t_stacks_info *stacks);
void		convert_av_to_int(char **av, t_stacks_info *stacks);

void		find_min_opers(t_stacks_info *stacks, t_oper_counter *min_opers);
void		find_current_rb_rrb(int idx,
				t_stacks_info *stacks, t_oper_counter *temp_opers);
void		find_current_ra_rra(int val,
				t_stacks_info *stacks, t_oper_counter *temp_opers);
void		find_current_ra(int val,
				t_stacks_info *stacks, t_oper_counter *temp_opers);

// termination
int			print_error(void);
void		free_strs(char **strs);
int			free_stacks(t_stacks_info stacks);

#endif