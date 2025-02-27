/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:18:52 by keiito            #+#    #+#             */
/*   Updated: 2025/02/09 19:44:58 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_int(char *string);

void	ft_putchar(char a);

void	error(void);

int	str_to_int(char *string)
{
	int	result;
	int	a;
	int	b;
	int	temp;

	a = 0;
	b = 0;
	result = 0;
	while (string[a] != '\0')
	{
		temp = string[a] - '0';
		result = result * 10 + temp;
		a++;
	}
	if (a == 10)
	{
		if (check_int(string) == 1)
			return (result);
		else
			return (-1);
	}
	else if (a > 10)
		return (-1);
	else
		return (result);
}

void	first_row(int n)
{
	int	a;

	a = 1;
	if (n == 1)
	{
		ft_putchar('o');
		ft_putchar('\n');
	}
	else
	{
		ft_putchar('o');
		while (a <= (n - 2))
		{
			ft_putchar('-');
			a++;
		}
		ft_putchar('o');
		ft_putchar('\n');
	}
}

void	middle_row(int ncolumn, int nrow)
{
	int	a;
	int	b;

	a = 1;
	while (a <= nrow - 2)
	{
		b = 1;
		ft_putchar('|');
		while (b <= ncolumn - 2)
		{
			ft_putchar(' ');
			b++;
		}
		if (ncolumn != 1)
		{
			ft_putchar('|');
		}
		ft_putchar('\n');
		a++;
	}
}

void	rush(int column, int row)
{
	if (column > 0 && row > 0)
	{
		first_row(column);
		if (row > 1)
		{
			middle_row(column, row);
			first_row(column);
		}
	}
	else
	{
		error();
	}
}
