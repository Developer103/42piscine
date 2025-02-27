/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:18:25 by tmizumur          #+#    #+#             */
/*   Updated: 2025/02/26 21:26:27 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	**get_init_map(int x, int y)
{
	int	**r;
	int	i;
	int	j;

	r = (int **)malloc(sizeof(int *) * y);
	i = 0;
	while (i < y)
	{
		r[i] = (int *)malloc(sizeof(int) * x);
		j = 0;
		while (j < x)
		{
			r[i][j] = 0;
			j++;
		}
		i++;
	}
	return (r);
}

int	**get_map(char *s, t_keys key)
{
	int	i;
	int	x;
	int	y;
	int	**r;

	r = get_init_map(key.columns, key.rows);
	i = 0;
	x = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			x = 0;
			y++;
		}
		else if (s[i] == key.empty)
			r[y][x++] = 0;
		else if (s[i] == key.obsct)
			r[y][x++] = -1;
		i++;
	}
	return (r);
}

int	**copy_map(int **map, t_keys key)
{
	int	**r;
	int	i;
	int	j;

	r = get_init_map(key.columns, key.rows);
	i = 0;
	while (i < key.rows)
	{
		j = 0;
		while (j < key.columns)
		{
			r[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (r);
}

char	search_key(int n, t_keys key)
{
	if (n == 0)
		return (key.empty);
	else if (n == -1)
		return (key.obsct);
	else if (n == 1)
		return (key.full);
	return ('X');
}

void	print_map(int **map, t_keys key)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	while (i < key.rows)
	{
		j = 0;
		while (j < key.columns)
		{
			temp = search_key(map[i][j], key);
			write(1, &temp, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
