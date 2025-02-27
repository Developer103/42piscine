/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:20:25 by keiito            #+#    #+#             */
/*   Updated: 2025/02/27 14:32:04 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	negative(int *num)
{
	if (*num == 0)
	{
		write(1, "0", 1);
	}
	else
	{
		if (*num < 0)
		{
			write(1, "-", 1);
			*num = -*num;
		}
	}
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	negative(&nb);
	if (nb > 10)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}
// int	main(void)
// {
// 	ft_putnbr(-21);
// 	return (0);
// }
