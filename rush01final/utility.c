/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:53:21 by keiito            #+#    #+#             */
/*   Updated: 2025/02/16 16:52:19 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	free_arrays(int **grid, int *rules)
{
	free(rules);
	free(grid);
}

int	has_duplicates(int **grid, int pos, int value, int size)
{
	int	a;
	int	b;

	a = 0;
	while (a < size)
	{
		if (grid[pos / size][a] == value)
			return (1);
		a++;
	}
	b = 0;
	while (b < size)
	{
		if (grid[b][pos % size] == value)
			return (1);
		b++;
	}
	return (0);
}

void	error(void)
{
	write(1, "Error\n", 6);
}

int	divi(int n)
{
	if (n % 4 == 0)
		return (n / 4);
	return (-1);
}

void	print_2d_grid(int **table, int n)
{
	int	x;
	int	y;
	int	z;

	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			z = table[y][x] + '0';
			write(1, &z, 1);
			if (x % (n) == (n) - 1)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			x++;
		}
		y++;
	}
}
