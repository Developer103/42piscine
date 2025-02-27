/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:03:25 by keiito            #+#    #+#             */
/*   Updated: 2025/02/26 21:47:57 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	get_display_map(t_max *max, int ***result, int f)
{
	int	a;
	int	b;
	int	init_y;
	int	init_x;

	if (f == 1)
	{
		a = max->x1;
		b = max->y1;
		init_x = max->x1 - (max->val - 1);
		init_y = max->y1 - (max->val - 1);
	}
	else
	{
		a = max->x2;
		b = max->y2;
		init_x = max->x2 - (max->val - 1);
		init_y = max->y2 - (max->val - 1);
	}
	fill_grid(init_x, init_y, max->val, result);
}

void	fill_grid(int x, int y, int max, int ***result)
{
	int	x_temp;
	int	y_temp;

	y_temp = y;
	while (y_temp < y + max)
	{
		x_temp = x;
		while (x_temp < x + max)
		{
			(*result)[y_temp][x_temp] = 1;
			x_temp++;
		}
		y_temp++;
	}
}

int	check_newline(char *s, int a)
{
	if (s[a] != '\0' && s[a] == '\n')
		return (1);
	return (0);
}

int	check_lines(char *s, int a, int init_rows, char keys[3])
{
	int	init_col;
	int	cols;
	int	rows;

	rows = 0;
	init_col = -1;
	cols = 0;
	while (s[a] != '\0' && (s[a] == keys[0] || s[a] == keys[1]))
	{
		cols = 0;
		skip(s, &a, keys, &cols);
		if (s[a] != '\0')
			a++;
		if (init_col == -1)
			init_col = cols;
		if (cols != init_col && s[a] != '\0')
			return (-1);
		rows++;
	}
	if (rows != init_rows || s[a - 1] != '\n' || s[a] == '\n')
		return (-1);
	return (0);
}

int	check_map(char *s)
{
	int		a;
	int		b;
	int		rows;
	char	keys[3];

	a = 0;
	rows = 0;
	while (s[a] != 0 && s[a] >= '0' && s[a] <= '9' && s[a + 3] != '\n')
	{
		rows *= 10;
		rows += s[a++] - '0';
	}
	b = a;
	while (s[a] >= 32 && s[a] <= 126 && a - b < 3)
	{
		keys[a - b] = s[a];
		a++;
	}
	if (b == 0 || a - b != 3 || s[a] != '\n' || key_dup(keys))
		return (-1);
	a++;
	if (check_lines(s, a, rows, keys) == -1)
		return (-1);
	return (0);
}
