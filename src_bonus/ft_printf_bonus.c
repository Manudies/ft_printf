/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:32:29 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/20 11:58:59 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;

	va_start(args, format);
	printed = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			printed += ft_parse_format(format, args);
			while (*format && !ft_strchr("cspdiuxX%", *format))
				format++;
		}
		else
			printed += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (printed);
}
