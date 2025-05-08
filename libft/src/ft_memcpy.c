/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:57:02 by mdiestre          #+#    #+#             */
/*   Updated: 2025/04/30 13:10:26 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*aux_src;
	unsigned char	*aux_dst;

	aux_dst = (unsigned char *)dst;
	aux_src = (unsigned char *)src;
	if (dst == src)
		return (dst);
	while (n > 0)
	{
		*aux_dst = *aux_src;
		aux_dst++;
		aux_src++;
		n--;
	}
	return (dst);
}
