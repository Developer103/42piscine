/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:29:29 by keiito            #+#    #+#             */
/*   Updated: 2025/02/09 18:51:38 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int column, int row);

void	error(void);

int		str_to_int(char *string);

int		check_int(char *string);

int	main(int argc, char *argv[])
{
	int	a;
	int	b;

	if (argc == 3)
	{
		a = str_to_int(argv[1]);
		if (a != -1)
		{
			b = str_to_int(argv[2]);
			rush(a, b);
			return (0);
		}
		error();
	}
	else if (argc >= 3 || argc == 2)
	{
		error();
	}
	else
	{
		rush(5, 3);
	}
	return (0);
}
