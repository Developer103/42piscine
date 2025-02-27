/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:10:31 by keiito            #+#    #+#             */
/*   Updated: 2025/02/10 18:14:11 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	strlength(char *string)
{
	unsigned int	length;

	length = 0;
	while (string[length] != '\0')
	{
		length++;
	}
	return (length);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	a;
	unsigned int	src_len;

	a = 0;
	src_len = strlength(src);
	if (n == 0)
	{
		return (src_len);
	}
	while (a < n - 1 && src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (src_len);
}
// int	main(void)
// {
// 	char test1[50];
// 	char *test2 = "Whatsup";
// 	printf("%d, %s", ft_strlcpy(test1, test2, 10), test1);
// 	return 0;
// }
