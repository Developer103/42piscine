/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:40:32 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/23 16:16:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

bool	parse_line(char *s, t_dict **dict);
bool	parse_dict_key(char **s, char **key);
bool	parse_dict_value(char **s, char **value);
bool	append_dict_node(t_dict **dict, char *key, char *value);

bool	parse_dict(t_dict **dict, int read_status, char **s, size_t count)
{
	size_t	i;

	i = 0;
	while ((read_status == 0 && i == 0) || i < count - 1)
	{
		if (!parse_line(s[i++], dict))
		{
			i = 0;
			while (i < count + 1)
				free(s[i++]);
			free(s);
			return (error_return(NULL, -1, NULL, NULL));
		}
	}
	i = 0;
	while (i < count + 1)
		free(s[i++]);
	free(s);
	return (true);
}

bool	parse_line(char *s, t_dict **dict)
{
	char	*key;
	char	*value;

	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			return (error_return("Dict Error\n", -1, NULL, NULL));
	while (ft_isspace(*s))
		s++;
	if (!parse_dict_key(&s, &key))
		return (false);
	if (*s++ != ':')
		return (error_return("Dict Error\n", -1, NULL, NULL));
	while (ft_isspace(*s))
		s++;
	if (!parse_dict_value(&s, &value))
		return (error_return(NULL, -1, key, NULL));
	if (*s)
	{
		free(key);
		return (error_return("Dict Error\n", -1, value, NULL));
	}
	return (append_dict_node(dict, key, value));
}

bool	parse_dict_key(char **s, char **key)
{
	size_t	digits;

	digits = 0;
	while (ft_isdigit((*s)[digits]))
		digits++;
	*key = (char *)malloc(digits + 1);
	if (!*key)
		return (false);
	ft_strncpy(*key, *s, digits);
	(*key)[digits] = '\0';
	*s += digits;
	return (true);
}

bool	parse_dict_value(char **s, char **value)
{
	size_t	len;

	len = 0;
	while (ft_isprintable((*s)[len]))
		len++;
	*value = (char *)malloc(len + 1);
	if (!*value)
		return (false);
	ft_strncpy(*value, *s, len);
	(*value)[len] = '\0';
	*s += len;
	return (true);
}

bool	append_dict_node(t_dict **dict, char *key, char *value)
{
	t_dict	*new;

	new = new_node(key, value);
	if (!new)
	{
		free(key);
		free(value);
		return (false);
	}
	if (*dict == NULL)
		*dict = new;
	else if (!insert_node(*dict, new))
	{
		free(key);
		free(value);
		return (error_return("Dict Error\n", -1, NULL, NULL));
	}
	return (true);
}
