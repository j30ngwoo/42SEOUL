/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:53:42 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/05/26 20:57:36 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		check_newline(char *result);
int		set_result(char buf[BUFFER_SIZE], char **result, int *result_len);

char	*free_str(char *str);
void	ft_strncpy(char *dest, char *src, int size);
void	ft_memncpy(char *dest, char *src, int size);
char	*ft_realloc(char *str, int size);

#endif