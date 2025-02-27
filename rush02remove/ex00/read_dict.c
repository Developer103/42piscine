/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 02:42:52 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/23 16:17:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		read_file(int fd, char **remainder);
size_t	count_splitted(char **s);

bool	read_dict(int fd, t_dict **dict)
{
	char	*remainder;
	int		read_status;
	char	**s;
	size_t	count;

	if (!is_strdup_success(&remainder, ""))
		return (false);
	read_status = 1;
	while (read_status)
	{
		read_status = read_file(fd, &remainder);
		if (read_status == -1)
			return (error_return(NULL, -1, remainder, NULL));
		s = ft_split(remainder, "\n");
		if (!s)
			return (error_return(NULL, -1, remainder, NULL));
		count = count_splitted(s);
		remainder = ft_strcpy(remainder, s[count - 1]);
		if (!parse_dict(dict, read_status, s, count))
			return (error_return(NULL, -1, remainder, NULL));
	}
	free(remainder);
	return (true);
}

int	read_file(int fd, char **remainder)
{
	int		res;
	char	buf[BUF_SIZE];

	res = read(fd, buf, BUF_SIZE - 1);
	if (res <= 0)
		return (res);
	buf[res] = '\0';
	*remainder = strjoin_dict(*remainder, buf);
	if (*remainder == NULL)
		return (-1);
	return (res);
}

size_t	count_splitted(char **s)
{
	size_t	count;

	count = 0;
	while (*s != NULL)
	{
		count++;
		s++;
	}
	return (count);
}
