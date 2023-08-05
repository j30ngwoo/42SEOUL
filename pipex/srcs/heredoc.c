/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:19:38 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/08/03 17:10:33 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	select_new_tempfile(t_pipex_info *info)
{
	int		file_num;
	char	*str_file_num;

	file_num = 0;
	while (1)
	{
		str_file_num = protected_itoa(file_num);
		info->infile_name = protected_strjoin(TEMPFILE_PATH, str_file_num);
		free(str_file_num);
		if (access(info->infile_name, F_OK) != 0)
			break ;
		free(info->infile_name);
		file_num++;
	}
}

void	read_from_stdin_save_to_tempfile(t_pipex_info *info)
{
	char	*line;

	info->infile_fd = protected_open(info->infile_name,
			O_WRONLY | O_CREAT, 0644);
	while (1)
	{
		line = protected_get_next_line(0);
		if (check_if_line_is_limiter(line, info))
		{
			free(line);
			break ;
		}
		else
		{
			write(info->infile_fd, line, ft_strlen(line));
			free(line);
		}
	}
	close(info->infile_fd);
	info->infile_fd = protected_open(info->infile_name,
			O_RDONLY | O_CREAT, 0644);
}

int	check_if_line_is_limiter(char *line, t_pipex_info *info)
{
	int	limiter_len;

	limiter_len = ft_strlen(info->limiter);
	if (ft_strncmp(info->limiter, line, limiter_len) == 0
		&& line[limiter_len] == '\n' && line[limiter_len + 1] == '\0')
		return (1);
	else
		return (0);
}
