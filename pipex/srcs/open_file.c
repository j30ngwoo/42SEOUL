/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:58:56 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/08/03 17:11:41 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_infile(t_pipex_info *info)
{
	info->infile_fd = protected_open(info->infile_name, O_RDONLY, 0);
}

void	open_outfile(t_pipex_info *info)
{
	info->outfile_fd = protected_open(info->outfile_name,
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

void	open_outfile_to_append_mode(t_pipex_info *info)
{
	info->outfile_fd = protected_open(info->outfile_name,
			O_WRONLY | O_CREAT | O_APPEND, 0644);
}
