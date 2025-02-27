/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:49:49 by keiito            #+#    #+#             */
/*   Updated: 2025/02/11 17:35:52 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	str_length(char *string)
{
	int	a;

	a = 0;
	while (string[a] != '\0')
	{
		a++;
	}
	return (a);
}

int	is_same(char *str, char *to_find, int a)
{
	int	b;

	b = 0;
	while (to_find[b] != '\0' && str[a] == to_find[b])
	{
		a++;
		b++;
	}
	if (b == str_length(to_find))
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	a;

	a = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[a] != '\0' && a + str_length(to_find) <= str_length(str))
	{
		if (str[a] == to_find[0])
		{
			if (is_same(str, to_find, a) == 1)
				return (str + a);
		}
		a++;
	}
	return (NULL);
}
// int main()
// {
// 	char test1[] = "He234fkdke341llo World";
// 	char test2[] = "";
// 	printf("%s\n", ft_strstr(test1, test2));
// }
