/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:05:07 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/22 20:10:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	**copy_words(char *str, char **s, size_t words_cnt, int delim_set[256]);
size_t	count_words(char *str, int delimiter_set[256]);
size_t	strlen_delimiter(char *str, int delimiter_set[256]);

char	**ft_split(char *str, char *charset)
{
	int		delim_set[256];
	size_t	words_count;
	char	**s;
	size_t	i;

	i = 0;
	while (i <= 255)
		delim_set[i++] = 0;
	while (*charset)
	{
		delim_set[(unsigned char)*charset] = 1;
		charset++;
	}
	words_count = count_words(str, delim_set);
	s = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!s)
		return (NULL);
	return (copy_words(str, s, words_count, delim_set));
}

size_t	count_words(char *str, int delimiter_set[256])
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str && !delimiter_set[(unsigned char)*str])
			count++;
		while (*str && !delimiter_set[(unsigned char)*str])
			str++;
		while (*str && delimiter_set[(unsigned char)*str])
			str++;
	}
	return (count);
}

size_t	strlen_delimiter(char *str, int delimiter_set[256])
{
	size_t	len;

	len = 0;
	while (*str && delimiter_set[(unsigned char)*str] == 0)
	{
		str++;
		len++;
	}
	return (len);
}

char	**copy_words(char *str, char **s, size_t words_cnt, int delim_set[256])
{
	size_t	i;

	i = 0;
	while (i < words_cnt)
	{
		while (delim_set[(unsigned char)*str])
			str++;
		s[i] = (char *)malloc(strlen_delimiter(str, delim_set) + 1);
		if (!s[i])
		{
			while (1)
			{
				if (i == 0)
					break ;
				i--;
				free(s[i]);
			}
			free(s);
			return (NULL);
		}
		ft_strncpy(s[i++], str, strlen_delimiter(str, delim_set));
		str += strlen_delimiter(str, delim_set);
	}
	s[words_cnt] = NULL;
	return (s);
}
