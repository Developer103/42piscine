/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:52:04 by keiito            #+#    #+#             */
/*   Updated: 2025/02/27 20:25:58 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	while (a < length)
	{
		if (f(tab[a]) != 0)
			count++;
		a++;
	}
	return (count);
}
// #include <stdio.h>
// int	even(char *s)
// {
// 	if (!s)
// 		return (0);
// 	return ((s[0] - '0') % 2);
// }
// int	main()
// {
// 	char	*tab[] = {"3", "2", "6", "5", 0};

// 	printf("%d", ft_count_if(tab, 5, &even));
// }
