/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:38:35 by keiito            #+#    #+#             */
/*   Updated: 2025/02/26 20:38:48 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	get_columns(char *s)
{
	int		i;
	int		flag;
	int		columns;

	i = 0;
	flag = 0;
	columns = 0;
	while (s[i] != '\0')
	{
		if (flag == 0 && s[i] == '\n')
			flag = 1;
		else if (flag == 1 && s[i] != '\n')
			columns++;
		else if (flag == 1 && s[i] == '\n')
			break ;
		i++;
	}
	return (columns);
}

char	*slide_s(char s[], int n)
{
	int		i;
	int		j;
	int		len;

	len = str_len(s);
	i = 0;
	j = n + 1;
	while (s[j])
	{
		s[i] = s[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}

t_keys	get_key(char **s, int argv)
{
	int		i;
	t_keys	r;

	i = 0;
	(void) argv;
	r.columns = get_columns(*s);
	r.rows = ty_atoi(s[0], &i);
	r.empty = s[0][i++];
	r.obsct = s[0][i++];
	r.full = s[0][i++];
	r.argv = argv;
	(*s) = slide_s(*s, i);
	return (r);
}
