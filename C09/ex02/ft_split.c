/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:36:46 by keiito            #+#    #+#             */
/*   Updated: 2025/02/27 13:56:52 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

char	*str_find(char *s, char *to_find);
int		chk_str(char *s, char c);

int	size_count(char *str, char *charset)
{
	int	r;

	r = 0;
	if (!chk_str(charset, *str))
		r++;
	while (*str)
	{
		if (chk_str(charset, *str) && str[1] != 0 && !chk_str(charset, str[1]))
			r++;
		str++;
	}
	return (r);
}

int	chk_str(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*cpy_str(char *s1, char *s2, int *n)
{
	char	*r;
	int		i;

	i = 0;
	while (chk_str(s2, s1[(*n)]))
		(*n)++;
	while (s1[(*n) + i] && !chk_str(s2, s1[(*n) + i]))
		i++;
	r = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s1[(*n) + i] && !chk_str(s2, s1[(*n) + i]))
	{
		r[i] = s1[(*n) + i];
		i++;
	}
	r[i] = '\0';
	while (s1[(*n) + i + 1] != 0 && chk_str(s2, s1[(*n) + i + 1]))
		i++;
	*n += i + 1;
	return (r);
}

char	**ft_split(char *str, char *charset)
{
	char	**r;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = size_count(str, charset);
	r = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size && *str != 0)
	{
		r[i] = cpy_str(str, charset, &j);
		i++;
	}
	r[i] = 0;
	return (r);
}
// int	main(int argc, char *argv[])
// {
// 	int	a = 0;
// 	(void)argc;
// 	printf("r1:%d\n", size_count(argv[1], argv[2]));
// 	while (a < size_count(argv[1], argv[2]))
// 	{
// 		printf("r%d:%s\n",a, ft_split(argv[1], argv[2])[a]);
// 		a++;
// 	}
// }
