/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:21:04 by keiito            #+#    #+#             */
/*   Updated: 2025/02/09 18:44:23 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_int(char *string)
{
	int	x;

	x = 0;
	while (string[x] != '\0')
	{
		if (string[x] > "2147483647"[x])
		{
			return (-1);
		}
		x++;
	}
	return (1);
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	error(void)
{
	ft_putchar('E');
	ft_putchar('r');
	ft_putchar('r');
	ft_putchar('o');
	ft_putchar('r');
	ft_putchar('\n');
}
