/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:47:02 by keiito            #+#    #+#             */
/*   Updated: 2025/02/10 11:54:35 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	a;
	int	t;

	a = 0;
	while (str[a] != '\0')
	{
		t = str[a];
		if (t < 97 || t > 122)
		{
			return (0);
		}
		a++;
	}
	return (1);
}
// int	main()
// {
// 	printf("%d\n", ft_str_is_lowercase(""));
// 	return 0;
// }
