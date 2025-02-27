/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:57:21 by keiito            #+#    #+#             */
/*   Updated: 2025/02/13 11:22:39 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_prime(int nb)
{
	int	a;

	a = 2;
	if (nb <= 1)
		return (0);
	else
	{
		while (a <= nb / a)
		{
			if (nb % a == 0)
				return (0);
			a++;
		}
		return (1);
	}
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 0;
	if (nb <= 2)
		return (2);
	if (is_prime(nb) == 1)
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}
// int	main()
// {
// 	printf("%d\n", ft_find_next_prime(2147483646));
// }
