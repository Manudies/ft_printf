/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:18:59 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/12 11:53:49 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	unsigned long	aux_ptr;
	char			*hex_ptr;
	int				len;

	if (!ptr)
		return (write(1, "0x0", 3));
	aux_ptr = (unsigned long)ptr;
	hex_ptr = ft_itoa_base(aux_ptr, 16, 0);
	if (!hex_ptr)
		return (0);
	write(1, "0x", 2);
	len = ft_strlen(hex_ptr);
	write(1, hex_ptr, len);
	len += 2;
	free(hex_ptr);
	return (len);
}
