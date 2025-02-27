/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:48:13 by keiito            #+#    #+#             */
/*   Updated: 2025/02/26 21:25:01 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

char	*string_append(char *dest, char *src, size_t *dest_size)
{
	size_t	src_len;
	size_t	new_size;
	char	*new_str;

	src_len = ft_strlen(src);
	new_size = *dest_size + src_len + 1;
	new_str = (char *)malloc(new_size);
	if (new_str == NULL)
		return (NULL);
	if (dest != NULL)
	{
		ft_strcpy(new_str, dest);
		free(dest);
	}
	ft_strcat(new_str, src);
	*dest_size = new_size;
	return (new_str);
}

int	error_return(int fd)
{
	close(fd);
	return (-1);
}

int	read_file(char *filename, char **result)
{
	int		fd;
	ssize_t	bytes_read;
	char	buf[MAX_BUFF];
	size_t	result_size;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	result_size = 1;
	*result = (char *)malloc(result_size);
	if (*result == NULL)
		return (error_return(fd));
	(*result)[0] = '\0';
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, sizeof(buf) - 1);
		buf[bytes_read] = '\0';
		*result = string_append(*result, buf, &result_size);
		if (*result == NULL)
			return (error_return(fd));
	}
	close(fd);
	return (0);
}

int	cnt_word(char *s)
{
	int	r;
	int	i;
	int	flag;

	i = 0;
	r = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\0')
			break ;
		if (s[i] == ' ')
			flag = 1;
		else if (flag == 1 && s[i] != ' ')
		{
			flag = 0;
			r++;
		}
		i++;
	}
	return (r);
}

char	**get_file_names(char *s)
{
	char	**r;
	int		i;
	int		j;
	int		flag;

	r = (char **)malloc(sizeof(char *) * cnt_word(s + 1));
	i = 0;
	flag = 1;
	j = 0;
	while (s[i] && !(s[i] == '\n' && s[i + 1] == '\0'))
	{
		if (s[i] == ' ')
			flag = 1;
		else if (flag == 1 && s[i] != ' ')
		{
			flag = 0;
			r[j++] = (s + i);
		}
		i++;
	}
	r[j] = NULL;
	return (r);
}
