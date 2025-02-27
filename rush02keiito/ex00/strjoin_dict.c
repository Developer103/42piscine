/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:22:28 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/23 14:22:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*strjoin_dict(char *dst, char *src)
{
	char	*new;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	new = (char *)malloc(dst_len + src_len + 1);
	if (!new)
	{
		free(dst);
		return (NULL);
	}
	ft_strcpy(new, dst);
	ft_strcat(new, src);
	free(dst);
	return (new);
}
