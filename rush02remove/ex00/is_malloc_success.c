/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_malloc_success.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:31:50 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/23 17:20:56 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

bool	is_malloc_success(char **s, size_t size)
{
	*s = (char *)malloc(size);
	if (!*s)
		return (false);
	return (true);
}

bool	is_strdup_success(char **dest, char *src)
{
	*dest = ft_strdup(src);
	if (!*dest)
		return (false);
	return (true);
}

bool	is_strjoin_dict_success(char **dest, char *src)
{
	*dest = strjoin_dict(*dest, src);
	if (!*dest)
		return (false);
	return (true);
}
