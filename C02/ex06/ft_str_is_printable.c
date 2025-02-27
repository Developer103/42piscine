/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:52:13 by keiito            #+#    #+#             */
/*   Updated: 2025/02/10 11:57:11 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	a;
	int	t;

	a = 0;
	while (str[a] != '\0')
	{
		t = str[a];
		if (t < 32 || t > 126)
		{
			return (0);
		}
		a++;
	}
	return (1);
}
// int	main()
// {
// 	printf("%d\n", ft_str_is_printable(""));
// 	return 0;
// }
