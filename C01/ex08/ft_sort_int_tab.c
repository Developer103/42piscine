/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:05:44 by keiito            #+#    #+#             */
/*   Updated: 2025/02/08 16:37:49 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
/*void	main()
{
	int list[] = {2, 8, 4, 1, 5, 9, 11, 8, 6, 8, 10};
	int	n = 0;
	int size = 11;
	ft_sort_int_tab(list, size);
	while (n < 11)
	{
		printf("%d ",list[n]);
		n++;
	}
}*/
