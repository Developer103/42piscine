/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:38:21 by keiito            #+#    #+#             */
/*   Updated: 2025/02/10 18:34:13 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	char_is_printable(char c)
{
	if (c < ' ' || c > '~')
	{
		return (0);
	}
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int		a;
	char	x;
	char	y;
	char	slash;

	a = 0;
	if (str[a] == '\0')
		return ;
	while (str[a] != '\0')
	{
		if (char_is_printable(str[a]) == 1)
		{
			write(1, &str[a], 1);
		}
		else
		{
			x = "0123456789abcdef"[str[a] / 16];
			y = "0123456789abcdef"[str[a] % 16];
			slash = '\\';
			write(1, &slash, 1);
			write(1, &x, 1);
			write(1, &y, 1);
		}
		a++;
	}
}
// int main()
// {
// 	ft_putstr_non_printable("HE\rLO\nWHAT\vSUP");
// 	return 0;
// }
