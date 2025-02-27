/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:22:28 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/22 21:26:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*strjoin_dict(char *remainder, char *buf)
{
	char	*new;
	size_t	remainder_len;
	size_t	buf_len;

	remainder_len = ft_strlen(remainder);
	buf_len = ft_strlen(buf);
	new = (char *)malloc(remainder_len + buf_len + 1);
	if (!new)
	{
		free(remainder);
		return (NULL);
	}
	ft_strcpy(new, remainder);
	ft_strcat(new, buf);
	free(remainder);
	return (new);
}
