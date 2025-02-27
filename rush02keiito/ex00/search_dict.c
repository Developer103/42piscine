/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 07:57:16 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/23 19:56:55 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

bool	print_zero_case(t_dict *dict, char *key, char **output);
bool	parse_key(t_dict *dict, char **key, char **output);

bool	search_dict(t_dict *dict, char *key, char **output)
{
	if (strnum_cmp(key, "0") == 0)
		return (search_one_digit(dict, key, output));
	while (*key)
	{
		if (!parse_key(dict, &key, output))
			return (false);
		if (ft_strlen(key) > 3)
		{
			if (!is_strjoin_dict_success(output, " "))
				return (false);
			if (!search_numerical_units(dict, key, output))
				return (false);
			if (!insert_bonus_units(key + 1, output))
				return (false);
		}
		key++;
		while (*key && *key == '0')
			key++;
	}
	return (true);
}

bool	parse_key(t_dict *dict, char **key, char**output)
{
	int	digits;

	digits = ft_strlen(*key);
	if (digits % 3 == 0)
	{
		if (!search_three_digits(dict, *key, output))
			return (false);
		*key += 2;
	}
	else if (digits % 3 == 2)
	{
		insert_bonus_hundred_two(*key, output, 2); //changed here
		if (!search_two_digits(dict, *key, output))
			return (false);
		*key += 1;
	}
	else if (digits % 3 == 1)
	{
		insert_bonus_hundred_two(*key, output, 1);
		return (search_one_digit(dict, *key, output));
	}
	return (true);
}
