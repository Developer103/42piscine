/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:35:42 by keiito            #+#    #+#             */
/*   Updated: 2025/02/17 13:29:53 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*list;
	int	a;

	list = (int *)malloc((max - min) * sizeof(int));
	a = 0;
	if (min >= max)
		return (NULL);
	while (a < max - min)
	{
		list[a] = min + a;
		a++;
	}
	return (list);
}
// int	main()
// {
// 	int	a;
// 	int	*l;

// 	l = ft_range(9, 10);
// 	a = 0;
// 	while (a < 10 - 9)
// 	{
// 		if (l)
// 			printf("%d ", l[a]);
// 		a++;
// 	}
// }
