/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:20:43 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/08 13:27:40 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_utoa(n);
	if (!str)
		return (0);
	write(1, str, ft_strlen(str));
	len = ft_strlen(str);
	free(str);
	return (len);
}
