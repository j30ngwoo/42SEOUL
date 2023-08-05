/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:35:27 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/04/08 16:29:47 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		precision;
	int		width;
	int		hash;
	int		space;
	int		plus;
	char	specifier;
}	t_flags;

int		ft_printf(const char *format, ...);
int		print_using_format(t_flags *flag, va_list ap);
int		move_format_index(const char *format);
int		count_specifier(const char *format);

// char, str (%c, %s, %%)
int		print_char(t_flags *flag, va_list ap);
int		print_str(t_flags *flag, va_list ap);

// hex (%x, %X)
int		print_hex(t_flags *flag, va_list ap);
int		puthex_using_format(unsigned int n, t_flags *flag);
int		puthex(unsigned int n, t_flags *flag);
int		count_hex_len(unsigned int n);
int		print_0x(unsigned int n, t_flags *flag);

// int (%d, %i)
int		print_int(t_flags *flag, va_list ap);
int		print_int_sign(int n, t_flags *flag);
int		putint_using_format(int n, t_flags *flag);
int		putint_nosign(int n);
int		count_int_len(int n);

//width: space and zero
int		print_space(int len);
int		print_zero(int len);

//unsigned int (%u)
int		print_unsinged_int(t_flags *flag, va_list ap);
int		putuint_using_format(unsigned int n, t_flags *flag);
int		putuint(unsigned int n);
int		count_uint_len(unsigned int n);

// initial setting
void	reset_flag(t_flags *flag);
void	set_flag(const char *format, t_flags *flag);
int		set_precision(const char *format, t_flags *flag);
int		set_width(const char *format, t_flags *flag);
int		count_digits(const char *format);

// ptr (%p)
int		print_ptr(t_flags *flag, va_list ap);
int		putptr_using_format(unsigned long long n);
int		count_ptr_len(unsigned long long n);

// utilities
int		natural_atoi(const char *format);
int		is_type(char c);
int		set_space_len(int print_len, t_flags *flag);

#endif