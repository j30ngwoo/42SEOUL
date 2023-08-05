/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:21:45 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/17 20:57:57 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	push_front(int value, int arr_max, t_stack *stack)
{
	stack->head = decrease_idx(arr_max, stack->head);
	stack->arr[stack->head] = value;
	stack->size++;
}

void	push_back(int value, int arr_max, t_stack *stack)
{
	stack->arr[stack->tail] = value;
	stack->tail = increase_idx(arr_max, stack->tail);
	stack->size++;
}

int	pop_front(int arr_max, t_stack *stack)
{	
	int	value;

	value = stack->arr[stack->head];
	stack->head = increase_idx(arr_max, stack->head);
	stack->size--;
	return (value);
}

int	pop_back(int arr_max, t_stack *stack)
{	
	int	value;

	stack->tail = decrease_idx(arr_max, stack->tail);
	value = stack->arr[stack->tail];
	stack->size--;
	return (value);
}
