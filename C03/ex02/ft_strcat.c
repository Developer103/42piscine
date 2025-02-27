/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:38:21 by keiito            #+#    #+#             */
/*   Updated: 2025/02/11 17:34:40 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	a;

	len = 0;
	a = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[a] != '\0')
	{
		dest[len] = src[a];
		a++;
		len++;
	}
	dest[len] = '\0';
	return (dest);
}
// int	main()
// {
// 	char test1[50] = "Hello world";
// 	char test2[] = ". What's up";
// 	ft_strcat(test1, test2);
// 	printf("%s\n", test1);
// }
