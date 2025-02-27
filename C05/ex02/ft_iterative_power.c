/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:14:24 by keiito            #+#    #+#             */
/*   Updated: 2025/02/12 19:11:46 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	a;
	int	n;

	a = 1;
	n = nb;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	while (a < power)
	{
		nb *= n;
		a++;
	}
	return (nb);
}
// int	main()
// {
// 	printf("%d\n", ft_iterative_power(0, 3));
// }
