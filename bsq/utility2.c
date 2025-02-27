/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:36:11 by keiito            #+#    #+#             */
/*   Updated: 2025/02/26 20:39:56 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;

	len = 0;
	while (src[len] != '\0')
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	len = 0;
	while (src[len] != '\0')
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

void	init_buf(char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}

char	*read_standard_input(void)
{
	char	buf[BUFF_SIZE];
	char	*r;
	int		i;

	init_buf(buf, BUFF_SIZE);
	read(0, buf, BUFF_SIZE);
	i = 0;
	r = ft_strdup(buf);
	return (r);
}

int	free_allocs(t_vars *vars, t_keys key, int i)
{
	int	a;

	a = 0;
	if (i != 1)
	{
		while (a < key.rows)
		{
			free(vars->map[a]);
			free(vars->map_cpy[a]);
			a++;
		}
		free(vars->map);
		free(vars->map_cpy);
	}
	free(vars->s);
	return (-1);
}

int	error_allocs(t_vars *vars)
{
	free(vars->s);
	write(1, "map error\n", 10);
	return (-1);
}
