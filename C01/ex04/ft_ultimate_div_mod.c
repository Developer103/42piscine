/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:29:50 by keiito            #+#    #+#             */
/*   Updated: 2025/02/08 16:30:33 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	ans;
	int	remain;

	ans = *a / *b;
	remain = *a % *b;
	*a = ans;
	*b = remain;
}
/*void	main()
{
	int a = 11;
	int b = 3;
	ft_ultimate_div_mod(&a, &b);
	printf("a, b: %d, %d", a, b);
}*/
