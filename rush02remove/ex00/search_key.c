/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:04:19 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/23 17:26:26 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

bool	search_three_digits(t_dict *dict, char *key, char **output)
{
	char	*s;

	s = find_key_value(dict, (char []){*key, '\0'});
	if (!s)
		return (error_return("Dict Error\n", -1, NULL, NULL));
	if (!is_strjoin_dict_success(output, s))
		return (false);
	if (!is_strjoin_dict_success(output, " "))
		return (false);
	s = find_key_value(dict, "100");
	if (!s)
		return (error_return("Dict Error\n", -1, NULL, NULL));
	if (!is_strjoin_dict_success(output, s))
		return (false);
	if (!insert_bonus_hundred(key, output))
		return (false);
	if (*(key + 1) != '0' || *(key + 2) != '0')
	{
		if (!is_strjoin_dict_success(output, " "))
			return (false);
		if (*(key + 1) != '0')
			return (search_two_digits(dict, key + 1, output));
		return (search_one_digit(dict, key + 2, output));
	}
	return (true);
}

bool	search_two_digits(t_dict *dict, char *key, char **output)
{
	char	*s;

	if (strnum_cmp((char []){*key, *(key + 1), '\0'}, "20") >= 0)
	{
		s = find_key_value(dict, (char []){*key, '0', '\0'});
		if (!s)
			return (error_return("Dict Error\n", -1, NULL, NULL));
		if (!is_strjoin_dict_success(output, s))
			return (false);
		if (*(key + 1) != '0')
		{
			if (!is_strjoin_dict_success(output, "-"))
				return (false);
			return (search_one_digit(dict, key + 1, output));
		}
	}
	else
	{
		s = find_key_value(dict, (char []){*key, *(key + 1), '\0'});
		if (!s)
			return (error_return("Dict Error\n", -1, NULL, NULL));
		if (!is_strjoin_dict_success(output, s))
			return (false);
	}
	return (true);
}

bool	search_one_digit(t_dict *dict, char *key, char **output)
{
	char	*s;

	s = find_key_value(dict, (char []){*key, '\0'});
	if (!s)
		return (error_return("Dict Error\n", -1, NULL, NULL));
	if (!is_strjoin_dict_success(output, s))
		return (false);
	return (true);
}

bool	search_numerical_units(t_dict *dict, char *key, char **output)
{
	char	*units;
	size_t	len;
	char	*s;

	len = ft_strlen(key);
	if (!is_malloc_success(&units, len + 1))
		return (false);
	units[0] = '1';
	units[len] = '\0';
	while (--len > 0)
		units[len] = '0';
	s = find_key_value(dict, units);
	if (!s)
		return (error_return("Dict Error\n", -1, units, NULL));
	free(units);
	if (!is_strjoin_dict_success(output, s))
		return (false);
	return (true);
}
