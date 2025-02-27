/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:13:17 by keiito            #+#    #+#             */
/*   Updated: 2025/02/16 16:52:08 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		set_blocks(int **blocks, int *rules, int pos, int size);

int		sq_root(int n);

void	print_2d_grid(int **table, int n);

void	error(void);

void	free_arrays(int **grid, int *rules);

int	rule_check(char *rules)
{
	int	a;

	a = 0;
	while (rules[a] != '\0')
	{
		if (a % 2 == 0)
		{
			if (rules[a] < '0' || rules[a] > '9')
			{
				return (-1);
			}
		}
		else
		{
			if (rules[a] != ' ')
			{
				return (-1);
			}
		}
		a++;
	}
	return (0);
}

int	len_str(char *string)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (string[a] != '\0')
	{
		if (string[a] != ' ')
			b++;
		a++;
	}
	return (b);
}

int	*make_rules(int *rules, int size, char *in)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (b < size)
	{
		if (in[a] != ' ')
		{
			rules[b] = in[a] - '0';
			b++;
		}
		a += 1;
	}
	return (rules);
}

void	set_and_print(int **grid, int *rules, int size)
{
	if (set_blocks(grid, rules, 0, size) == 1)
		print_2d_grid(grid, size);
	else
	{
		write(1, "Error\n", 6);
	}
}

int	main(int argc, char *argv[])
{
	int	a;
	int	*rules;
	int	**grid;
	int	s;

	a = -1;
	if (argc != 2)
	{
		error();
		return (0);
	}
	s = len_str(argv[1]) / 4;
	rules = (int *)malloc(len_str(argv[1]) * sizeof(int));
	grid = (int **)malloc(s * sizeof(int *));
	while (++a < s)
		grid[a] = (int *)malloc(s * sizeof(int));
	if (rule_check(argv[1]) == -1 || len_str(argv[1]) % 4 != 0)
	{
		error();
		return (0);
	}
	rules = make_rules(rules, len_str(argv[1]), argv[1]);
	set_and_print(grid, rules, s);
	free_arrays(grid, rules);
	return (0);
}
