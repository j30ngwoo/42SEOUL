/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:29:49 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/05/26 21:20:59 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_list_str(t_list **head, char *str)
{
	t_list	*next_node;

	if (str != NULL)
		free(str);
	if (head == NULL)
		return (NULL);
	while (*head)
	{
		next_node = (*head)->next;
		free(*head);
		*head = next_node;
	}
	return (NULL);
}

char	*free_fd_node(t_list **head, int fd)
{
	t_list	*now_node;
	t_list	*next_node;

	if (*head == NULL)
		return (NULL);
	if ((*head)->fd == fd)
	{
		next_node = (*head)->next;
		free(*head);
		*head = next_node;
		return (NULL);
	}
	now_node = *head;
	while (now_node->next != NULL)
	{
		next_node = now_node->next->next;
		if (now_node->next->fd == fd)
		{
			free(now_node->next);
			now_node->next = next_node;
			return (NULL);
		}
		now_node = now_node->next;
	}
	return (NULL);
}

char	*free_fd_node_str(t_list **head, int fd, char *result)
{
	free_fd_node(head, fd);
	free_list_str(0, result);
	return (NULL);
}

void	ft_memncpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_realloc(char *str, int size)
{
	char	*temp;
	int		i;

	i = 0;
	temp = str;
	str = malloc(size);
	if (str == NULL)
		return (free_list_str(0, temp));
	if (temp != NULL)
	{
		while (i < size && temp[i] != '\0')
		{
			str[i] = temp[i];
			i++;
		}
	}
	free_list_str(0, temp);
	return (str);
}
