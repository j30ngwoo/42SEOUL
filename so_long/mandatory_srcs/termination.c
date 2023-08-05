/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:10:20 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/30 15:22:14 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	perror_exit(void)
{
	perror("Error\n");
	exit(1);
}

void	exit_with_message(char *message)
{
	ft_putstr_fd("Error\n: ", 2);
	ft_putstr_fd(message, 2);
	exit(1);
}

int	game_shutdown(void)
{
	ft_putstr("Game closed.\n");
	exit(0);
}
