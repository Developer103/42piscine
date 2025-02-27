/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:49:14 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/23 20:14:17 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

bool	insert_bonus_hundred(char *key, char **output)
{
	if (key[0] != '0' && (key[1] != '0' || key[2] != '0'))
	{
		if (!is_strjoin_dict_success(output, " and"))
			return (false);
	}
	return (true);
}

bool	insert_bonus_hundred_two(char *key, char **output, int digits)
{
	if (*(key - 1) == '0' && !*(key + 2) && digits == 2)
	{
		if (!is_strjoin_dict_success(output, "and "))
			return (false);
	}
	if (*(key - 1) == '0' && !*(key + 1) && digits == 1)
	{
		if (!is_strjoin_dict_success(output, "and "))
			return (false);
	}
	return (true);
}

bool	insert_bonus_units(char *key, char **output)
{
	size_t	i;

	i = 0;
	while (key[i])
	{
		if (key[i] != '0')
		{
			if (ft_strlen(key) - i == 1 || ft_strlen(key) - i == 2)
			{
				if (!is_strjoin_dict_success(output, " "))
					return (false);
			}
			else
			{
				if (!is_strjoin_dict_success(output, ", "))
					return (false);
			}
			break ;
		}
		i++;
	}
	return (true);
}
