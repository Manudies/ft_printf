/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:57:35 by mdiestre          #+#    #+#             */
/*   Updated: 2025/04/30 13:11:23 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*aux_dst;
	const unsigned char	*aux_src;

	aux_dst = (unsigned char *)dst;
	aux_src = (const unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (aux_dst < aux_src)
		return (ft_memcpy(dst, src, len));
	while (len > 0)
	{
		len--;
		aux_dst[len] = aux_src[len];
	}
	return (dst);
}
