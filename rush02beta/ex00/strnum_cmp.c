/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnum_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:09:10 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/22 21:27:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	strnum_cmp(char *s_num1, char *s_num2)
{
	size_t	s_num1_len;
	size_t	s_num2_len;

	s_num1_len = ft_strlen(s_num1);
	s_num2_len = ft_strlen(s_num2);
	if (s_num1_len > s_num2_len) //桁数を比較
		return (1);
	else if (s_num1_len < s_num2_len)
		return (-1);
	while (*s_num1 && *s_num2 && *s_num1 == *s_num2)
	{
		s_num1++;
		s_num2++;
	}
	if (*s_num1 > *s_num2) //数字比較
		return (1);
	else if (*s_num1 < *s_num2)
		return (-1);
	return (0);
}
