/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:00:49 by keiito            #+#    #+#             */
/*   Updated: 2025/02/26 20:41:16 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	change_max(t_max *max, int a, int b, int **dp)
{
	max->val = dp[a][b];
	max->x1 = b;
	max->y1 = a;
	max->x2 = 0;
	max->y2 = 0;
}

void	calculate(int ***dp, int a, int b)
{
	int	c;
	int	d;
	int	e;

	c = (*dp)[a][b - 1];
	d = (*dp)[a - 1][b];
	e = (*dp)[a - 1][b - 1];
	if ((*dp)[a][b] == -1)
		(*dp)[a][b] = 0;
	else if ((*dp)[a][b - 1] <= d && (*dp)[a][b - 1] <= e)
		(*dp)[a][b] = (*dp)[a][b - 1] + 1;
	else if (d <= c && d <= e)
		(*dp)[a][b] = d + 1;
	else if (e <= d && e <= c)
		(*dp)[a][b] = e + 1;
}

void	solve(int ***dp, t_keys keys)
{
	int	rows;
	int	columns;
	int	a;
	int	b;

	rows = keys.rows;
	columns = keys.columns;
	a = 0;
	while (a < rows)
	{
		b = 0;
		while (b < columns)
		{
			if ((*dp)[a][b] == -1)
				(*dp)[a][b] = 0;
			else if (a == 0 || b == 0)
				(*dp)[a][b] = 1;
			else
				calculate(dp, a, b);
			b++;
		}
		a++;
	}
}

void	get_max(int **dp, t_max *max, t_keys *keys)
{
	int	a;
	int	b;
	int	l;

	a = 0;
	while (a < keys->rows)
	{
		b = 0;
		while (b < keys->columns)
		{
			l = max->x2;
			if (!max->val || dp[a][b] > max->val)
				change_max(max, a, b, dp);
			else if (dp[a][b] == max->val && ((!l && b < max->x1) || b < l))
			{
				max->x2 = b;
				max->y2 = a;
			}
			b++;
		}
		a++;
	}
}
