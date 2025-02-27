/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:27:57 by keiito            #+#    #+#             */
/*   Updated: 2025/02/27 20:40:50 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	a;

	a = 0;
	while (a < length)
	{
		f(tab[a]);
		a++;
	}
}
// void	mizuki(int a)
// {
// 	char	c = a + '0';
// 	write(1, "FUNNY", 5);
// 	write(1, &c, 1);
// }

// int	main()
// {
// 	int	tab = 2;
// 	ft_foreach(&tab, 1, &mizuki);
// }
