/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:49:49 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/05/26 21:22:46 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*result;
	int				result_len;
	int				read_len;

	result = NULL;
	if (set_list(&list, fd, &read_len, &result_len) == 0)
		return (NULL);
	while (read_len != 0 && !check_nl(result))
	{
		if (list->now_node->buf[0] == '\0')
		{
			read_len = read(fd, list->now_node->buf, BUFFER_SIZE);
			if (read_len == -1)
				return (free_fd_node_str(&list, fd, result));
			list->now_node->buf[read_len] = '\0';
		}
		if (list->now_node->buf[0] != '\0'
			&& set_result(list->now_node->buf, &result, &result_len) == 0)
			return (free_list_str(&list, result));
	}
	if (read_len == 0)
		free_fd_node(&list, fd);
	return (result);
}

int	set_list(t_list **head, int fd, int *read_len, int *result_len)
{
	t_list	*node;

	*read_len = 1;
	*result_len = 1;
	node = *head;
	while (node != NULL && node->next != NULL && fd != node->fd)
		node = node->next;
	if (node == NULL)
	{
		node = malloc(sizeof(t_list));
		if (node == NULL)
			return ((int)free_list_str(head, NULL));
		*head = node;
		node_init(node, *head, fd);
	}
	else if (fd != node->fd)
	{
		node->next = malloc(sizeof(t_list));
		if (node->next == NULL)
			return ((int)free_list_str(head, NULL));
		node_init(node->next, *head, fd);
	}
	else
		(*head)->now_node = node;
	return (1);
}

void	node_init(t_list *node, t_list *head, int fd)
{
	node->fd = fd;
	node->next = NULL;
	node->buf[0] = '\0';
	head->now_node = node;
}

int	check_nl(char *result)
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
	if (*result == 0)
		return (0);
	ft_memncpy(*result + *result_len - 1, buf, now_len);
	*result_len += now_len;
	(*result)[new_result_len - 1] = '\0';
	ft_memncpy(buf, buf + now_len, BUFFER_SIZE - now_len + 1);
	return (1);
}
