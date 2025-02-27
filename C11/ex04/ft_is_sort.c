/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:55:18 by keiito            #+#    #+#             */
/*   Updated: 2025/02/27 20:28:37 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	a;
	int	sort;
	int	sort_rev;

	a = 0;
	sort = 0;
	sort_rev = 0;
	while (a < length - 1)
	{
		if (f(tab[a], tab[a + 1]) > 0)
			sort += 1;
		a++;
	}
	a = 0;
	while (a < length - 1)
	{
		if (f(tab[a], tab[a + 1]) < 0)
			sort_rev += 1;
		a++;
	}
	if (sort == 0 || sort_rev == 0)
		return (1);
	return (0);
}
// #include <stdio.h>
// int	cmp(int i, int j)
// {
// 	return (i - j);
// }
// int	main()
// {
// 	int	tab[] = {10, 7, 6, 5, 4};

// 	printf("%d", ft_is_sort(tab, 5, &cmp));
// }
