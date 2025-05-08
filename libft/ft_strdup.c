/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:37 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/05 09:43:21 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	s_len;

	s_len = ft_strlen(s1);
	str = malloc(s_len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s_len + 1);
	return (str);
}
