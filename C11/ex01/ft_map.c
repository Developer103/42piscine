/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:35:38 by keiito            #+#    #+#             */
/*   Updated: 2025/02/27 15:47:21 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	i;

	result = (int *)malloc(length * sizeof(int));
	if (!result)
		return (0);
	i = 0;
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
// #include <stdio.h>
// int	add(int a)
// {
// 	return (a + 1);
// }
// int	main()
// {
// 	int inp[] = {4, 3, 1};
// 	printf("%d", ft_map(inp, 3, &add)[0]);
// }
