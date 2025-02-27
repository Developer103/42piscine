/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:05:53 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/23 17:01:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

bool	read_key(int argc, char **argv, char **key)
{
	char	buf[PIPE_BUF + 1];
	int		res;

	if (argc == 2 || argc == 3)
	{
		*key = argv[argc - 1];
	}
	else if (argc == 1)
	{
		if (!is_strdup_success(key, "\0"))
			return (false);
		res = read(STDIN_FILENO, buf, PIPE_BUF);
		if (res == -1)
			return (false);
		if (buf[res - 1] == '\n')
			res -= 1;
		buf[res] = '\0';
		if (!is_strjoin_dict_success(key, buf))
			return (false);
	}
	else
		return (false);
	return (true);
}
