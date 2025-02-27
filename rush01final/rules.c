/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:48:48 by tuchikaw          #+#    #+#             */
/*   Updated: 2025/02/16 19:44:49 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	check_top(int **blocks, int *rules, int pos, int size)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (pos / size == size - 1)
	{
		while (i < size)
		{
			if (blocks[i][pos % size] > max)
			{
				max = blocks[i][pos % size];
				count++;
			}
			i++;
		}
		if (rules[pos % size] != count)
			return (1);
	}
	return (0);
}

int	check_bottom(int **blocks, int *rules, int pos, int size)
{
	int	i;
	int	max;
	int	count;

	i = size - 1;
	max = 0;
	count = 0;
	if (pos / size == size - 1)
	{
		while (i >= 0)
		{
			if (blocks[i][pos % size] > max)
			{
				max = blocks[i][pos % size];
				count++;
			}
			i--;
		}
		if (rules[size + pos % size] != count)
			return (1);
	}
	return (0);
}

int	check_left(int **blocks, int *rules, int pos, int size)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (pos % size == size - 1)
	{
		while (i < size)
		{
			if (blocks[pos / size][i] > max)
			{
				max = blocks[pos / size][i];
				count++;
			}
			i++;
		}
		if (rules[size * 2 + pos / size] != count)
			return (1);
	}
	return (0);
}

int	check_right(int **blocks, int *rules, int pos, int size)
{
	int	i;
	int	max_size;
	int	visible_towers;

	i = size - 1;
	max_size = 0;
	visible_towers = 0;
	if (pos % size == size - 1)
	{
		while (i >= 0)
		{
			if (blocks[pos / size][i] > max_size)
			{
				max_size = blocks[pos / size][i];
				visible_towers++;
			}
			i--;
		}
		if (rules[size * 3 + pos / size] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_rules(int **blocks, int *rules, int pos, int size)
{
	if (check_left(blocks, rules, pos, size) == 1)
		return (1);
	if (check_right(blocks, rules, pos, size) == 1)
		return (1);
	if (check_top(blocks, rules, pos, size) == 1)
		return (1);
	if (check_bottom(blocks, rules, pos, size) == 1)
		return (1);
	return (0);
}
