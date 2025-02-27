/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:46:03 by keiito            #+#    #+#             */
/*   Updated: 2025/02/17 13:32:00 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	a;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc ((max - min) * sizeof(int));
	a = 0;
	if (!(range[a]))
		return (-1);
	while (a < max - min)
	{
		(*range)[a] = min + a;
		a++;
	}
	return (max - min);
}
// int	main()
// {
// 	int	*a;
// 	int	n;

// 	printf("%d\n", ft_ultimate_range(&a, 3, 10));
// 	n = 0;
// 	while (n < 7)
// 	{
// 		if (a)
// 			printf("%d ",a[n]);
// 		n++;
// 	}
// }
