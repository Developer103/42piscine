/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:24:07 by keiito            #+#    #+#             */
/*   Updated: 2025/02/18 16:03:25 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

int	str_len(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

char	*string_copy(char *str)
{
	int		a;
	char	*copy;

	a = 0;
	copy = (char *)malloc((str_len(str) + 1) * sizeof(char));
	if (!(copy))
		return (0);
	while (str[a] != '\0')
	{
		copy[a] = str[a];
		a++;
	}
	copy[a] = 0;
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	int			a;

	result = (t_stock_str *)malloc ((ac + 1) * sizeof(t_stock_str));
	a = 0;
	if (!(result))
		return (0);
	while (a < ac)
	{
		result[a].size = str_len(av[a]);
		result[a].str = av[a];
		result[a].copy = string_copy(av[a]);
		a++;
	}
	result[a].size = 0;
	result[a].str = 0;
	result[a].copy = 0;
	return (result);
}
// int	main()
// {
// 	int	size = 3;
// 	char *temp[3] = {"hello", "hey", "whatsup"};
// 	t_stock_str *test;
// 	test = ft_strs_to_tab(size, temp);
// 	int	a = 0;
// 	while (a < size)
// 	{
// 		printf("Size:%d, ",test[a].size);
// 		printf("Str: %s, ", test[a].str);
// 		printf("Copy: %s\n", test[a].copy);
// 		a++;
// 	}
// }
