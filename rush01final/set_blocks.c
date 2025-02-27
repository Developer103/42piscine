/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_blocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:08:31 by keiito            #+#    #+#             */
/*   Updated: 2025/02/16 16:22:17 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include <stdio.h>

int		check_rules(int **blocks, int *rules, int size, int pos);

int		has_duplicates(int **grid, int pos, int value, int size);

void	print_2d_grid(int **table, int n);

int	set_blocks(int **blocks, int *rules, int pos, int size)
{
	int	height;

	height = 0;
	if (pos == size * size)
		return (1);
	while (++height <= size)
	{
		if (has_duplicates(blocks, pos, height, size) == 0)
		{
			blocks[pos / size][pos % size] = height;
			if (check_rules(blocks, rules, pos, size) == 0)
			{
				if (set_blocks(blocks, rules, pos + 1, size) == 1)
					return (1);
			}
			blocks[pos / size][pos % size] = 0;
		}
	}
	return (0);
}
//Erase later
// int	main()
// {
// 	int	a = 0;
// 	int	b = 0;
// 	int	i = 0;
// 	int **grid;
// 	int *rules;
// 	rules = malloc(4 * sizeof(int));
// 	grid = malloc(4 * sizeof(int*));
// 	while (i < 4)
// 	{
// 		grid[i] = (int *)malloc(4 * sizeof(int));
// 		i++;
// 	}
// 	set_blocks(grid, rules, 0, 4);
// 	while (a < 4)
// 	{
// 		b = 0;
// 		while (b < 4)
// 		{
// 			printf("%d ", grid[a][b]);
// 			if (b % 4 == 3)
// 				printf("\n");
// 			b++;
// 		}
// 		a++;
// 	}
// }