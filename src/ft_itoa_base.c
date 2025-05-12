/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:14:33 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/12 11:51:33 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	ft_count_digits(unsigned int n, int base)
{
	int	len;

	len = 1;
	while (n / base)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned int n, int base, int uppercase)
{
	char			*digits;
	char			*str;
	int				len;
	unsigned int	tmp;

	digits = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	if (uppercase)
		digits = "0123456789ABCDEF";
	tmp = n;
	len = ft_count_digits(n, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = digits[n % base];
		n /= base;
	}
	return (str);
}
