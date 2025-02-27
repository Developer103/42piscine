/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:05:43 by keiito            #+#    #+#             */
/*   Updated: 2025/02/10 18:30:07 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	a;
	int	f;

	a = 0;
	f = 1;
	while (str[a] != '\0')
	{
		if (str[a] >= 97 && str[a] <= 122 && f == 1)
		{
			str[a] -= 32;
			f = 0;
		}
		else if (str[a] >= 65 && str[a] <= 90 && f == 1)
			f = 0;
		else if (str[a] >= 65 && str[a] <= 90 && f == 0)
			str[a] += 32;
		else if (str[a] >= 97 && str[a] <= 122 && f == 0)
			f = 0;
		else if (str[a] >= '0' && str[a] <= '9')
			f = 0;
		else
			f = 1;
		a++;
	}
	return (str);
}
// int	main()
// {
// 	char t[] = "AabBc cdDeE 1jkjkj9ghgyguj hel-lo+world";
// 	printf("%s\n", ft_strcapitalize(t));
// 	return 0;
// }
