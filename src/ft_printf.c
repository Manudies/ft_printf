/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:45:26 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/08 13:37:52 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
				len += ft_print_char(va_arg(args, int));
			else if (format[i] == 's')
				len += ft_print_str(va_arg(args, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				len += ft_print_int(va_arg(args, int));
			else if (format[i] == '%')
				len += write(1, "%", 1);
			else if (format[i] == 'u')
				len += ft_print_unsigned(va_arg(args, unsigned int));
			else
				len += write(1, &format[i], 1);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
