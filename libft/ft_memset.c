/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:48:35 by mdiestre          #+#    #+#             */
/*   Updated: 2025/04/30 13:06:24 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*aux;

	aux = (unsigned char *)b;
	while (len > 0)
	{
		*aux = (unsigned char)c;
		aux++;
		len--;
	}
	return (b);
}
