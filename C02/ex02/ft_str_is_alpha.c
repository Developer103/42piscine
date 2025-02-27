/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:22:09 by keiito            #+#    #+#             */
/*   Updated: 2025/02/10 11:50:35 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	a;
	int	t;

	a = 0;
	while (str[a] != '\0')
	{
		t = str[a];
		if (t < 65 || t > 122)
		{
			return (0);
		}
		else if (t > 90 && t < 97)
		{
			return (0);
		}
		a++;
	}
	return (1);
}
// int	main()
// {
// 	printf("%d\n", ft_str_is_alpha("dkfjdk fdjk"));
// 	return 0;
// }
