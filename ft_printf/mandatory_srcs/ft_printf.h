/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:28:52 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/28 22:23:48 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	print_using_format(const char *format, va_list ap);
int	print_char(va_list ap);
int	print_str(va_list ap);
int	print_percent(void);
int	print_hex(va_list ap, char x_or_X);
int	recursion_hex(unsigned int hex, char x_or_X);
int	print_int(va_list ap);
int	recursion_int(int n, int sign);
int	print_uint(va_list ap);
int	recursion_uint(unsigned int n);
int	print_ptr(va_list ap);
int	recursion_ptr(unsigned long long ptr);

#endif