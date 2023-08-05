/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:16:51 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/03/13 17:27:53 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z')
		|| ('a' <= c && c <= 'z'));
}