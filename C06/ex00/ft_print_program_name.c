/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:41:56 by keiito            #+#    #+#             */
/*   Updated: 2025/02/12 19:46:48 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		len;
	char	*name;

	(void) argc;
	len = 0;
	name = argv[0];
	while (name[len] != '\0')
	{
		len++;
	}
	write(1, name, len);
	write(1, "\n", 1);
	return (0);
}
