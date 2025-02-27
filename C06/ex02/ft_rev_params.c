/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:19:45 by keiito            #+#    #+#             */
/*   Updated: 2025/02/12 21:29:15 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		a;
	int		len;
	char	*n;

	a = 0;
	if (argc <= 1)
		return (0);
	while (argc - 1 - a > 0)
	{
		n = argv[argc - 1 - a];
		len = 0;
		while (n[len] != '\0')
			len++;
		write(1, argv[argc - 1 - a], len);
		write(1, "\n", 1);
		a++;
	}
	return (0);
}
