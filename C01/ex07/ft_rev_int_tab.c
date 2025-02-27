/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:20:21 by keiito            #+#    #+#             */
/*   Updated: 2025/02/08 16:32:56 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	a;
	int	half;

	a = 0;
	half = size / 2;
	while (a <= half)
	{
		temp = tab[a];
		tab[a] = tab[a + (size - (1 + 2 * a))];
		tab[a + (size - (1 + 2 * a))] = temp;
		a++;
	}
}
/*void	main(void)
{
	int	list[] = {1, 2, 3, 4, 6, 10, 4, 222, 100};
	int	a = 0;
	int	size = 9;
	ft_rev_int_tab(list, size);
	while (a < size)
	{
		printf("%d ", list[a]);
		a++;
	}
}*/
