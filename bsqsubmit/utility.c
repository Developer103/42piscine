/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:24:51 by keiito            #+#    #+#             */
/*   Updated: 2025/02/26 20:31:23 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	key_dup(char keys[3])
{
	if (keys[0] == keys[1] || keys[0] == keys[2] || keys[1] == keys [2])
		return (1);
	return (0);
}

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ty_atoi(char *s, int *n)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s[i])
	{
		if ('0' <= s[i] && s[i] <= '9' && s[i + 3] != '\n')
			r = r * 10 + (s[i] - '0');
		else
			break ;
		i++;
	}
	if (i == 0)
		return (-1);
	*n = (*n) + i;
	return (r);
}

void	skip(char *s, int *a, char keys[3], int *cols)
{
	while (s[*a] != '\n' && (s[*a] == keys[0] || s[*a] == keys[1]))
	{
		(*cols)++;
		(*a)++;
	}
}

void	ty_replace(char *s)
{
	while (*s)
	{
		if (*s == '\n' || *s == ' ' || *s <= 32 || *s >= 127)
			*s = '\0';
		s++;
	}
	return ;
}
