/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:21 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/05 09:36:54 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*aux;
	size_t				i;

	aux = (const unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (aux[i] == (unsigned char)c)
			return ((void *)aux + i);
		i++;
		n--;
	}
	return (NULL);
}
