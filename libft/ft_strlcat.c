/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:42 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/02 12:27:33 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	max;
	size_t	i;

	dst_len = ft_strlen(dst);
	max = size - dst_len -1;
	i = 0;
	if (size <= dst_len)
		return (size + ft_strlen(src));
	while (i < max && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}
