/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:53:42 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/05/26 20:57:33 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	struct s_list	*next;
	struct s_list	*now_node;
}	t_list;

char	*get_next_line(int fd);
int		set_list(t_list **head, int fd, int *read_len, int *result_len);
void	node_init(t_list *node, t_list *head, int fd);
int		check_nl(char *result);
int		set_result(char buf[BUFFER_SIZE + 1], char **result, int *result_len);

char	*free_list_str(t_list **head, char *str);
char	*free_fd_node(t_list **head, int fd);
char	*free_fd_node_str(t_list **head, int fd, char *result);
void	ft_memncpy(char *dest, char *src, int size);
char	*ft_realloc(char *str, int size);

#endif
