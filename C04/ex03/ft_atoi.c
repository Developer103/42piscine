/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:47:06 by keiito            #+#    #+#             */
/*   Updated: 2025/02/15 18:30:36 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int		a;
	int		negative;
	long	ans;

	a = 0;
	ans = 0;
	negative = 1;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == ' ')
		a++;
	while (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			negative *= -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		ans *= 10;
		ans += str[a] - '0';
		a++;
	}
	return (ans * negative);
}
int	main()
{
	printf("%d\n", ft_atoi(" \n ---+--+1234567"));
}
