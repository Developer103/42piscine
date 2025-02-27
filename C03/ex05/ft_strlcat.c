/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:19:53 by keiito            #+#    #+#             */
/*   Updated: 2025/02/11 17:37:15 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	str_length(char *string)
{
	unsigned int	a;

	a = 0;
	while (string[a] != '\0')
	{
		a++;
	}
	return (a);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	a;

	a = 0;
	len = str_length(dest);
	if (str_length(dest) < size)
	{
		while (src[a] != '\0' && len < size - 1)
		{
			dest[len] = src[a];
			a++;
			len++;
		}
		dest[len] = '\0';
		return (len + str_length(src) - a);
	}
	else
		return (str_length(src) + size);
}
// int	main()
// {
// 	char test1[14] = "Hello world";
// 	char test2[] = ". What's up";
// 	printf("%d\n", ft_strlcat(test1, test2, 15));
// 	printf("%s\n", test1);
// }
