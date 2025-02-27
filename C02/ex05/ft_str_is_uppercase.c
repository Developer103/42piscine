/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:49:37 by keiito            #+#    #+#             */
/*   Updated: 2025/02/10 11:55:41 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	a;
	int	t;

	a = 0;
	while (str[a] != '\0')
	{
		t = str[a];
		if (t < 65 || t > 90)
		{
			return (0);
		}
		a++;
	}
	return (1);
}
// int	main()
// {
// 	printf("%d\n", ft_str_is_uppercase(""));
// 	return 0;
// }
