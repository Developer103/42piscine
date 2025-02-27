/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:04:10 by keiito            #+#    #+#             */
/*   Updated: 2025/02/17 21:11:50 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	str_len(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

int	total_len(char **strs, int size)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	c = 0;
	while (a < size)
	{
		b = 0;
		while (strs[a][b] != '\0')
		{
			b++;
			c++;
		}
		a++;
	}
	return (c);
}

void	append(char *str1, char *str2, int *pos)
{
	int	a;

	a = 0;
	while (str2[a] != '\0')
	{
		str1[*pos] = str2[a];
		a++;
		(*pos)++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		a;
	int		c;
	char	*result;
	int		len;

	a = 0;
	c = 0;
	len = total_len(strs, size) + str_len(sep) * (size - 1);
	result = (char *)malloc (len * sizeof(char));
	while (a < size)
	{
		append(result, strs[a], &c);
		if (a != size - 1)
			append(result, sep, &c);
		a++;
	}
	result[c] = '\0';
	return (result);
}
int	main()
{
	char *strs[] = {"hello", "whatsup", "yello"};
	char *sep = " ";
	int	size = 3;
	printf("%s", ft_strjoin(size, strs, sep));
}
