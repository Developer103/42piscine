/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:00:14 by keiito            #+#    #+#             */
/*   Updated: 2025/02/26 10:46:53 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	str_len(char *string)
{
	int	a;

	a = 0;
	while (string[a] != '\0')
	{
		if (string[a] == '+' || string[a] == '-')
			return (-1);
		a++;
	}
	return (a);
}

int	has_same(char *string)
{
	int	a;
	int	j;

	a = 0;
	while (a < str_len(string) - 1)
	{
		j = a + 1;
		while (j < str_len(string))
		{
			if (string[a] == string[j])
				return (-1);
			j++;
		}
		a++;
	}
	return (0);
}

void	to_deci(long n, char *base)
{
	char	letter;

	if (n >= str_len(base))
	{
		to_deci(n / str_len(base), base);
	}
	letter = base[n % str_len(base)];
	write(1, &letter, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;

	n = nbr;
	if (str_len(base) < 2 || has_same(base) == -1 || str_len(base) == -1)
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	to_deci(n, base);
}
int	main()
{
	ft_putnbr_base(-26, "0123456789ABCDEF");
}






void recursive()
	if (n < str_len(base))
		write(1, "0123456789ABCDEF"[2], 1);
