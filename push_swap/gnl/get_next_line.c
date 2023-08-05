/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:49:49 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/05/26 21:24:23 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*result;
	int			result_len;
	int			read_len;

	read_len = 1;
	result_len = 1;
	result = NULL;
	while (read_len != 0 && !check_newline(result))
	{
		if (buf[0] == 0)
		{
			read_len = read(fd, buf, BUFFER_SIZE);
			if (read_len == -1)
				return (free_str(result));
			buf[read_len] = '\0';
		}
		if (buf[0] != '\0' && set_result(buf, &result, &result_len) == 0)
			return (free_str(result));
	}
	return (result);
}

int	check_newline(char *result)
{
	int	i;

	if (result == 0)
		return (0);
	i = 0;
	while (result[i] != '\n' && result[i] != '\0')
		i++;
	if (result[i] == '\n')
		return (1);
	else
		return (0);
}

int	set_result(char buf[BUFFER_SIZE], char **result, int *result_len)
{
	int	now_len;
	int	new_result_len;

	now_len = 0;
	while (buf[now_len] != '\n' && buf[now_len] != '\0')
		now_len++;
	if (buf[now_len] == '\n')
		now_len++;
	new_result_len = *result_len + now_len;
	*result = ft_realloc(*result, new_result_len);
	if (*result == NULL)
		return (0);
	ft_strncpy(*result + *result_len - 1, buf, now_len);
	*result_len += now_len;
	(*result)[new_result_len - 1] = '\0';
	ft_memncpy(buf, buf + now_len, BUFFER_SIZE - now_len + 1);
	return (1);
}
