/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:29:59 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/22 15:05:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*itr;

	itr = dest;
	while (*itr)
		itr++;
	while (nb-- > 0 && *src)
		*itr++ = *src++;
	*itr = '\0';
	return (dest);
}
