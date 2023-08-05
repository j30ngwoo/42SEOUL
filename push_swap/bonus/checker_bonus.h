/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:07:12 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/20 16:43:45 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# define NO_PRINT 0
# define PRINT 1

# include "../gnl/get_next_line.h"
# include "../opers/opers.h"

int		exec_oper(t_stacks_info *stacks);
void	exec_sx(char *oper, t_stacks_info *stacks);
void	exec_px(char *oper, t_stacks_info *stacks);
void	exec_rx(char *oper, t_stacks_info *stacks);
void	exec_rrx(char *oper, t_stacks_info *stacks);

#endif