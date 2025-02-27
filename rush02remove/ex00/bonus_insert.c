/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:49:14 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/23 17:28:36 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdio.h>

bool	insert_bonus_hundred(char *key, char **output)
{
	printf("zero: %c, one: %c, two: %c\n", key[0], key[1], key[2]);
	if (key[0] != '0' && (key[1] != '0' || key[2] != '0'))
	{
		if (!is_strjoin_dict_success(output, " and"))
			return (false);
	}
	else if (key[0] == '0' )
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
			if (!is_strjoin_dict_success(output, ", "))
				return (false);
			break ;
		}
		i++;
	}
	return (true);
}
