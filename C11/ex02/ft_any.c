/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:47:37 by keiito            #+#    #+#             */
/*   Updated: 2025/02/27 20:24:30 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	while (tab[count])
		count++;
	while (a < count)
	{
		if (f(tab[a]) != 0)
			return (1);
		a++;
	}
	return (0);
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
// 	char	*tab[] = {"3", "2", "6", "4", 0};

// 	printf("%d", ft_any(tab, &even));
// }
