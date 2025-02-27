/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:07:15 by keiito            #+#    #+#             */
/*   Updated: 2025/02/08 16:29:47 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*void	main(void)
{
	int div;
	int mod;
	ft_div_mod(10, 4, &div, &mod);
	printf("%d, %d\n", div, mod);
}*/
