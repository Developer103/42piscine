/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:15:55 by keiito            #+#    #+#             */
/*   Updated: 2025/02/11 17:35:21 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len;
	unsigned int	a;

	len = 0;
	a = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[a] != '\0' && a < nb)
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
// 	ft_strncat(test1, test2, 3);
// 	printf("%s\n", test1);
// }
