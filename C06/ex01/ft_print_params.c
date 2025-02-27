/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:47:40 by keiito            #+#    #+#             */
/*   Updated: 2025/02/22 17:12:37 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		a;
	int		len;
	char	*name;

	a = 1;
	len = 0;
	while (a < argc)
	{
		name = argv[a];
		len = 0;
		while (name[len] != '\0')
		{
			len++;
		}
		write(1, name, len);
		write(1, "\n", 1);
		a++;
	}
	return (0);
}
